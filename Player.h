#pragma once
#include "Organism.h"

class Player :
	public Organism
{
public:
	Player();
	~Player();

	int finalAttackPower;
	int level;

};

