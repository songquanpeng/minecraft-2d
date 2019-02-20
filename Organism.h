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

	float speed;
	int blood;
	Point positionRelativeToScreen;
	Point realPosition;

	int attakPower;
	int attackRange;
	int attackInterval;
	int armor;
	int desiredDirection();
};

