#include "Organism.h"



Organism::Organism()
{
	constructorTool();
}

// 提供给定的实际坐标，单位为像素
Organism::Organism(Point givenRealPosition)
{
	Organism();
	realPosition = givenRealPosition;
	constructorTool();
}

void Organism::constructorTool()
{
	name = "Organism";
	isDead = false;
	speed = getRealMove(SPEED_ARGUMENT);
	isPenetrateAble = false;
}

Organism::~Organism()
{

}

int Organism::desiredDirection()
{
	return rand() % 5;
}

int Organism::getRealMove(int speed)
{
	return (int)((double)(speed*SPEED_SCALAR) / (double)(FPS));
}

void Organism::killed()
{
	qDebug() << name << " be killed";
	isDead = true;
}

void Organism::beAttacked(int demage)
{
	int realDemage = min(demage - armor * ARMOR_PROTECTION_RATIO, 0);
	blood -= realDemage;
	qDebug() << name << " be attacked, demage: " << demage << " real demage: " << realDemage << "remainingBlood: " << blood;
	if (blood <= 0)
	{
		blood = 0;
		killed();
	}
}


int Organism::min(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

