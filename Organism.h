#pragma once
#include "Constant.h"
#include <Qstring>
#include <QImage>


class Organism
{
public:
	Organism();
	Organism(Point givenRealPosition);
	~Organism();
	QString name;

	int speed; //实际移动的像素数，因此为整数
	int blood;
	Point positionRelativeToScreen; // 单位应更新为像素
	Point realPosition; // 单位：像素；不依赖屏幕位置;注意：一般要*SIZE

	int attakPower;
	int attackRange;
	int attackInterval;
	int armor;
	int facing;
	int desiredDirection();
	int getRealMove(int speed);
	QImage image;
};

