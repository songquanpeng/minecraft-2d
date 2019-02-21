#include "Player.h"



Player::Player()
	:Organism()
{
	speed = getRealMove(PLAYER_SPEED);
	blood = PLAYER_BLOOD;
	armor = PLAYER_ARMOR;
	attakPower = PLAYER_ATTACK_POWER;
	attackRange = PLAYER_ATTACK_RANGE;
	attackInterval = PLAYER_ATTACK_INTERVAL;
	level = 0;
	positionRelativeToScreen.row = 6;
	positionRelativeToScreen.col = 10;
}


Player::~Player()
{
}
