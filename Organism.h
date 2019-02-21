#pragma once
#include "Constant.h"
#include <cstdlib>
#include <ctime>
#include <Qstring>


class Organism
{
public:
	Organism();
	~Organism();
	QString name;

	int speed; //实际移动的像素数，因此为整数
	int blood;
	Point positionRelativeToScreen; // 单位：格
	Point realPosition; // 单位：像素；不依赖屏幕位置

	int attakPower;
	int attackRange;
	int attackInterval;
	int armor;
	int desiredDirection();
	int getRealMove(int speed);
};

