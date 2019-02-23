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
	Point realPosition; // 单位：像素；不依赖屏幕位置
	bool isPenetrateAble;
	int attakPower;
	int attackRange;
	int attackInterval;
	int armor;
	int facing;
	int desiredDirection();
	int getRealMove(int speed); // 此函数的功能与名称描述不符；不要轻易修改
	bool isDead;
	QImage image;

	void killed();
	void beAttacked(int demage);
	void constructorTool();
	int min(int a, int b);
};

