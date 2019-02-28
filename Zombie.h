#pragma once
#include "Organism.h"
class Zombie :
	public Organism
{
public:
	Zombie(Point givenRealPosition);
	~Zombie();
	//int desiredDirection();
};

