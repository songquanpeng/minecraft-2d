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
	dropItemNum = 2;
	dropItemType = STONE;
	experience = 0.4;
	attakPower = ZOMBIE_ATTACK_POWER;
}


Zombie::~Zombie()
{
}

//// 负责僵尸的前进方向
//int Zombie::desiredDirection()
//{
//	int getRandomNumber = rand() % 7;
//	if (getRandomNumber < 5)
//	{
//		direction = getRandomNumber;
//	}
//	else if (getRandomNumber == 5)
//	{
//		attackNow = true;
//		attackDirection = direction;
//	}
//
//	return direction;
//}
