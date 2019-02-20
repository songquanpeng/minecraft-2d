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

	int attakPower;
	int armor;
	int desiredDirection();
};

