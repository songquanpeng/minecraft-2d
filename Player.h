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
	double level;
	void experienceAdd(double gain);
	int currentArticleType;
	void loadAticleList();
	void changeCurrentHold(int step);

	// 此数据成员未在构造函数中初始化；使用之前请确保其值正确
	Point realGrid;
};

