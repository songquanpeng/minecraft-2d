#pragma once
#include <cstdlib>
#include <ctime>
#include <QString>
#include <QSettings>
#include "Constant.h"
#include "Core.h"

//const int WORLD_ROW = 270;
//const int WORLD_COL = 480;



class World
{
public:
	World();
	~World();
	unsigned short int board[WORLD_ROW][WORLD_COL]; // ÐÐ£¬ÁÐ
	bool createWorld(int id);
	void resetGame(int id);
	bool startGame(int id);
	bool saveToFile(int id);
	Core *core;

private:
	int getRandomInt();
	bool generatePlayerConfig(int id);
	int getRandomInt(int lower, int upper);
	int getSuitableCube(int _row, int _col);
	QString getPath(int id);
	QString getArchiveFilePath(int id);
	bool isArchiveExist(int id);
	Point riverStartPoint;
	Point riverEndPoint;
	bool isWater(int _row, int _col);
	bool deleteArchive(QString path);
};

