#pragma once
#include "Organism.h"

class Player :
	public Organism
{
public:
	Player();
	~Player();
	int articleList[MAX_ARTICLE_NUM];
	int finalAttackPower;
	int level;
	int currentArticleType;
	void loadAticleList();
	void changeCurrentHold(int step);
};

