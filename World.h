#pragma once
#include <cstdlib>
#include <ctime>
#include <QString>

const int WORLD_ROW = 270;
const int WORLD_COL = 480;

class World
{
public:
	World();
	~World();
	unsigned char board[WORLD_ROW][WORLD_COL]; // ÐÐ£¬ÁÐ
	bool createWorld(int id);
	void resetGame(int id);
	bool startGame(int id);
	bool saveToFile(int id);


private:
	int getRandomInt();
	int getSuitableCube();
	QString getPath(int id);
};

