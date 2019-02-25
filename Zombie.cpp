#include "Zombie.h"



Zombie::Zombie(Point givenRealPosition)
	:Organism(givenRealPosition)
{
	image = QImage(":/lancher/image/game/zombie2.png");
	blood = ZOMBIE_BLOOD;
	armor = ZOMBIE_ARMOR;
	name = "Zombie";
	hurtSound = "sound/minecraft/zombie_hurt.mp3";
	deadSound = "sound/minecraft/zombie_death.mp3";

}


Zombie::~Zombie()
{
}
