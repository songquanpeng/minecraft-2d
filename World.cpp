#include "World.h"
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>

World::World()
{
	srand(static_cast<unsigned int>(time(0)));

}


World::~World()
{

}

bool World::createWorld(int id)
{
	// 创建并储存玩家信息
	generatePlayerConfig(id);
	// 确定河流的起始点与结束点
	riverStartPoint.row = getRandomInt(5, WORLD_ROW);
	riverStartPoint.col = 0;
	riverEndPoint.row = getRandomInt(5, WORLD_ROW);
	riverEndPoint.col = WORLD_COL;

	for(int row=0; row < WORLD_ROW; row++)
		for (int col = 0; col < WORLD_COL; col++)
		{
			board[row][col] = (unsigned short int)getSuitableCube(row, col);
		}

	return saveToFile(id);
}

void World::resetGame(int id)
{
	QString archivePath = getPath(id);
	deleteArchive(archivePath);
}

bool World::startGame(int id)
{
	if (!isArchiveExist(id))
	{
		if (!createWorld(id))
		{
			return false;
		}
	}
	core = new Core(getPath(id));
	core->show();
	return true;
}

inline int World::getRandomInt()
{
	return rand() % 10 + 1;
}

bool World::generatePlayerConfig(int id)
{
	QSettings config(getPath(id)+"/player.ini", QSettings::IniFormat);
	config.setValue("window_col", 0);
	config.setValue("window_row", 0);

	config.setValue("row", 6*SIZE);
	config.setValue("col", 10*SIZE);
	config.setValue("blood", PLAYER_BLOOD);
	config.setValue("level", 0);
	config.setValue("attack", PLAYER_ATTACK_POWER);
	config.setValue("armor", PLAYER_ARMOR);
	config.setValue("current", SWORD);

	config.beginWriteArray("article");
	for (int i = 0; i < 7; i++)
	{
		config.setArrayIndex(i);
		config.setValue("number", 0);
	}

	for (int i = 10; i < 17; i++)
	{
		config.setArrayIndex(i);
		config.setValue("number", 1);
	}
	config.endArray();
	return false;
}

inline int World::getRandomInt(int lower, int upper)
{
	return rand() % (upper - lower + 1) + lower;
}

int World::getSuitableCube(int _row, int _col)
{
	// 可以返回的值：
	// 1：草方块（代表大地）
	// 3：圆石方块（代表山地）
	// 5：树叶方块（代表森林）
	// 6：水方块（代表河流）

	// 默认生成几率：
	// 草方块：6
	// 圆石方块：2
	// 树叶方块：2
	// 水方块：由函数直接确定
	if (isWater(_row, _col))
	{
		return WATER;
	}
	else
	{
		int randomNumber = getRandomInt();
		if (randomNumber <= EARTH_PROBABILITY)
		{
			return GRASS;
		}
		else if(randomNumber <= (EARTH_PROBABILITY+WOOD_PROBABILITY))
		{
			return LEAF;
		}
		else
		{
			return STONE;
		}
	}
}

QString World::getPath(int id)
{
	return "archive/" + QString::number(id);
}

QString World::getArchiveFilePath(int id)
{
	return getPath(id) + "/map.txt";
}

bool World::isArchiveExist(int id)
{
	QFileInfo fileInfo(getArchiveFilePath(id));
	
	return fileInfo.isFile();
}

bool World::isWater(int _row, int _col)
{
	int standardRow = ((double)(riverStartPoint.row - riverEndPoint.row) / (double)(-riverEndPoint.col))*_col + riverStartPoint.row;
	if (abs(standardRow - _row) <= RIVER_WIDTH && getRandomInt() < RIVER_PROBABILITY)
	{
		return true;
	}
	return false;
}

bool World::deleteArchive(QString path)
{

	if (path.isEmpty())
	{
		return false;
	}

	QDir dir(path);
	if (!dir.exists())
	{
		return true;
	}

	dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
	QFileInfoList fileList = dir.entryInfoList();
	foreach(QFileInfo fi, fileList)
	{
		if (fi.isFile())
		{
			fi.dir().remove(fi.fileName());
		}
		else
		{
			deleteArchive(fi.absoluteFilePath());
		}
	}
	return dir.rmpath(dir.absolutePath());
}


bool World::saveToFile(int id)
{
	QDir *dir = new QDir();
	bool isExist = dir->exists(getPath(id));
	bool isSuccess;
	if (!isExist)
	{
		isSuccess = dir->mkpath(getPath(id));
	}
	if (isSuccess)
	{
		QFile *file = new QFile(getPath(id) + "/map.txt");
		if (file->open(QIODevice::WriteOnly | QIODevice::Text))
		{
			QTextStream input(file);
			for (int row = 0; row < WORLD_ROW; row++)
			{
				for (int col = 0; col < WORLD_COL; col++)
				{
					input << board[row][col] << " ";
				}
				input << endl;
			}
			file->close();
			delete file;
			return true;
		}
	}
	return false;
}