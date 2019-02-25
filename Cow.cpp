#include "Cow.h"



Cow::Cow(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	image = QImage(":/lancher/image/game/cow2.png");
	blood = COW_BLOOD;
	armor = COW_ARMOR;
	name = "Cow";
	hurtSound = "sound/minecraft/cow_hurt.mp3";
	// deadSound = "sound/minecraft/skeleton_death.mp3";

}


Cow::~Cow()
{
}
