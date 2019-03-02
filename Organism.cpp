#include "Organism.h"



Organism::Organism()
{
	constructorTool();
}

// 提供给定的实际坐标，单位为像素
Organism::Organism(Point givenRealPosition)
{
	Organism();
	realPosition = givenRealPosition;
	constructorTool();
}

void Organism::constructorTool()
{
	name = "Organism";
	isDead = false;
	speed = getRealMove(SPEED_ARGUMENT);
	isPenetrateAble = false;
	hurtSound = "sound/minecraft/cow_hurt.mp3";
	deadSound = "sound/minecraft/cow.mp3";
	direction = 0;
	attackDirection = direction;
	attackNow = false;
	dropItemNum = 2;
	dropItemType = MEAT;
	experience = 0.2;
	inScreen = true;
}

Organism::~Organism()
{

}

// 决定方向以及是否攻击（attackNow）
int Organism::desiredDirection() 
{
	int getRandomNumber = rand() % 7;
	if (getRandomNumber < 5)
	{
		direction = getRandomNumber;
	}
	else if(getRandomNumber == 5)
	{
		attackNow = true;
		attackDirection = direction;
	}

	return direction;
}

int Organism::getRealMove(int speed)
{
	return (int)((double)(speed*SPEED_SCALAR) / (double)(FPS));
}

void Organism::killed()
{
	qDebug() << name << " be killed";
	isDead = true;
}

void Organism::beAttacked(int demage)
{
	int realDemage = max(demage - armor * ARMOR_PROTECTION_RATIO, 1);
	blood -= realDemage;
	qDebug() << name << " be attacked, demage: " << demage << " real demage: " << realDemage << "remainingBlood: " << blood;
	if (blood <= 0)
	{
		blood = 0;
		killed();
		// soundPlayer.setMedia(QUrl::fromLocalFile(deadSound));
	}
	//else
	//{
	soundPlayer.setMedia(QUrl::fromLocalFile(hurtSound));
	//}
	if (name != "Player")
	{
		soundPlayer.play();
	}
}


int Organism::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

