#include "Player.h"



Player::Player()
	:Organism()
{
	speed = PLAYER_SPEED;
	blood = PLAYER_BLOOD;
	armor = PLAYER_ARMOR;
	attakPower = PLAYER_ATTACK_POWER;
	attackRange = PLAYER_ATTACK_RANGE;
	attackInterval = PLAYER_ATTACK_INTERVAL;
	level = 0;
	positionRelativeToScreen.row = 0;
	positionRelativeToScreen.col = 0;
}


Player::~Player()
{
}
