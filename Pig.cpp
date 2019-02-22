#include "Pig.h"



Pig::Pig(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	image = QImage(":/lancher/image/game/pig.png");
	blood = PIG_BLOOD;
	armor = PIG_ARMOR;
	name = "Pig";
}


Pig::~Pig()
{
}
