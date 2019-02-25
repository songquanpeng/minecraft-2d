#include "Sheep.h"



Sheep::Sheep(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	image = QImage(":/lancher/image/game/sheep2.png");
	blood = SHEEP_BLOOD;
	armor = SHEEP_ARMOR;
	name = "Sheep";
	hurtSound = "sound/minecraft/sheep_hurt.mp3";
	// deadSound = "sound/minecraft/skeleton_death.mp3";

}


Sheep::~Sheep()
{
}
