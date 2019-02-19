#pragma once
#include <array>

const int WORLD_ROW = 270;
const int WORLD_COL = 480;

class World
{
public:
	World();
	~World();
	void createWorld(int id);
	void resetGame(int id);
	void startGame(int id);
};

