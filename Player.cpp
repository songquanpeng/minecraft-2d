#include "Player.h"



Player::Player()
	:Organism()
{
	image = QImage(":/lancher/image/game/steven.png");
	name = "player";
	blood = PLAYER_BLOOD;
	armor = PLAYER_ARMOR;
	attakPower = PLAYER_ATTACK_POWER;
	attackRange = PLAYER_ATTACK_RANGE;
	attackInterval = PLAYER_ATTACK_INTERVAL;
	level = 0;
	positionRelativeToScreen.row = 6*SIZE;
	positionRelativeToScreen.col = 10*SIZE;
	finalAttackPower = attakPower;
	attackRange = PLAYER_ATTACK_RANGE;
	currentArticleType = BOW;
	loadAticleList();
}


Player::~Player()
{
}

void Player::loadAticleList()  // TODO: load article list
{
	articleList[BASE] = 0;
	articleList[EARTH] = 5;
	articleList[WOOD] = 5;
	articleList[LEAF] = 5;
	articleList[STONE] = 5;
	articleList[GLASS] = 5;
	articleList[WATER] = 5;

	articleList[SWORD] = 1;
	articleList[AXE] = 1;
	articleList[BOW] = 1;
	articleList[PICK] = 1;
	articleList[SHOVEL] = 1;
	articleList[ARROW] = 5;
	articleList[MEAT] = 6;
}

// 参数只能为1或者-1
void Player::changeCurrentHold(int step)
{
	qDebug() << "you are changing current hold, step: " << step;

	while (true)
	{
		currentArticleType += step;
		if (currentArticleType < 0) currentArticleType = MAX_ARTICLE_NUM - 1;
		currentArticleType %= MAX_ARTICLE_NUM; //保证不越数组界
		if (articleList[currentArticleType] != NULL && articleList[currentArticleType] > 0) // 说明下一个可以
		{
			break;
		}
	}
}
