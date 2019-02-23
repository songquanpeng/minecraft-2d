#pragma once
#include <QDebug>
struct Point
{
	int row;
	int col;
	bool operator== (const Point otherPoint) const
	{
		if (row == otherPoint.row && col == otherPoint.col)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

const float ARMOR_PROTECTION_RATIO = 0.5;

const int WORLD_ROW = 270;
const int WORLD_COL = 480;
const int SIZE = 40;
const int SCREEN_ROW = 27;
const int SCREEN_COL = 48;

const int RIVER_WIDTH = 7;
const int RIVER_PROBABILITY = 9;
const int STONE_PROBABILITY = 2;
const int WOOD_PROBABILITY = 2;
const int EARTH_PROBABILITY = 6;

const int BASE = 0;
const int GLASS = 1;
const int EARTH = 2;
const int STONE = 3;
const int WOOD = 4;
const int LEAF = 5;
const int WATER = 6;

// 不应改动
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int STAY = 4;

const int WINDOW_MOVE_STEP = 1;

// 生物属性
const int MOBS_NUMBER = 60;
// cattle
const int CATTLE_BLOOD = 15;
const int CATTLE_ARMOR = 4;
const int CATTLE_SPEED = 3;

// sheep
const int SHEEP_BLOOD = 7;
const int SHEEP_ARMOR = 0;
const int SHEEP_SPEED = 5;

// pig
const int PIG_BLOOD = 7;
const int PIG_ARMOR = 1;
const int PIG_SPEED = 6;

// zombie
const int ZOMBIE_BLOOD = 10;
const int ZOMBIE_ARMOR = 2;
const int ZOMBIE_SPEED = 6;
const int ZOMBIE_ATTACK_POWER = 3;
const int ZOMBIE_ATTACK_RANGE = 1;
const int ZOMBIE_ATTACK_INTERVAL = 2;

// skeleton
const int SKELETON_BLOOD = 5;
const int SKELETON_ARMOR = 1;
const int SKELETON_SPEED = 6;
const int SKELETON_ATTACK_POWER = 4;
const int SKELETON_ATTACK_RANGE = 5;
const int SKELETON_ATTACK_INTERVAL = 3;

// creeper
const int CREEPER_BLOOD = 4;
const int CREEPER_ARMOR = 1;
const int CREEPER_SPEED = 7;
const int CREEPER_ATTACK_POWER = 9;
const int CREEPER_ATTACK_RANGE = 3;

// spider
const int SPIDER_BLOOD = 5;
const int SPIDER_ARMOR = 1;
const int SPIDER_SPEED = 7;
const int SPIDER_ATTACK_POWER = 3;
const int SPIDER_ATTACK_RANGE = 1;
const int SPIDER_ATTACK_INTERVAL = 2;

// player
const int PLAYER_BLOOD = 10;
const int PLAYER_ARMOR = 2;
const int PLAYER_SPEED = 6;
const int PLAYER_ATTACK_POWER = 2;
const int PLAYER_ATTACK_RANGE = 1;
const int PLAYER_ATTACK_INTERVAL = 1;

// move
const int FPS = 60;
// SPEED*SPEED_SCALAR = FPS*REAL_MOVE
// 以玩家每s移动一格（40像素为基准)
// SPEED*SPEED_SCALAR = FPS*SIZE
// =>	
const float SPEED_SCALAR = (double)(FPS*SIZE) / (double)(PLAYER_SPEED);
const int SPEED_ARGUMENT = 6;
const int MOBS_MOVE_TIMER = 500;
const int DISTANCE_TO_SCREEN_BORDER = 1*SIZE;
const int SCREEN_MOVE_DISTANCE = 1;
const bool ENABLE_CHECK_ALL = true;
