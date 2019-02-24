#include "Skeleton.h"



Skeleton::Skeleton(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	image = QImage(":/lancher/image/game/skeleton2.png");
	blood = SKELETON_BLOOD;
	armor = SKELETON_BLOOD;
	name = "Skeleton";
	hurtSound = "sound/minecraft/sketon_hurt.mp3";
	deadSound = "sound/minecraft/skeleton_death.mp3";

}


Skeleton::~Skeleton()
{
}
