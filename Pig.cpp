#include "Pig.h"



Pig::Pig(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	image = QImage(":/lancher/image/game/pig2.png");
	blood = PIG_BLOOD;
	armor = PIG_ARMOR;
	name = "Pig";

	hurtSound = "sound/minecraft/pig_hurt.mp3";

}


Pig::~Pig()
{
}
