#include "Pig.h"



Pig::Pig(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	speed = getRealMove(PIG_SPEED);
	blood = PIG_BLOOD;
	armor = PIG_ARMOR;
}


Pig::~Pig()
{
}
