#pragma once
#include "Organism.h"
class Skeleton :
	public Organism
{
public:
	Skeleton(Point givenRealPosition);
	~Skeleton();
	int desiredDirection();
};

