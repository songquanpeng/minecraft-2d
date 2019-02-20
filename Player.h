#pragma once
#include "Organism.h"

class Player :
	public Organism
{
public:
	Player();
	~Player();
	float speed;
	float attakPower;
	int level;

};

