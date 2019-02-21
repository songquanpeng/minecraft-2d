#include "Pig.h"



Pig::Pig(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	image = QImage(":/lancher/image/game/pig.png");
	speed = getRealMove(PIG_SPEED);
	blood = PIG_BLOOD;
	armor = PIG_ARMOR;
}


Pig::~Pig()
{
}
