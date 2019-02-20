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
	for(int row=0; row < WORLD_ROW; row++)
		for (int col = 0; col < WORLD_COL; col++)
		{
			board[row][col] = (unsigned char)getSuitableCube();
		}

	return saveToFile(id);
}

void World::resetGame(int id)
{

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

int World::getSuitableCube()
{
	// TODO
	return getRandomInt();
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