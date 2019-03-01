#include "Arrow.h"



Arrow::Arrow(int direction_, Point realGrid)
{
	// 设置位置坐标；更新两个坐标（realGrid, realPosition）
	realPosition.row = realGrid.row * SIZE;
	realPosition.col = realGrid.col * SIZE;
	direction = direction_;

	image = QImage(":/lancher/image/game/arrow.png");
	attakPower = 4; // TODO: 此处参数需要调优
	speed = 25;
	isPenetrateAble = false;  // 存在问题，如果打开，生物将一次性受到多次伤害
	isMoving = true;
	isPlayer = false;
}

Arrow::~Arrow()
{

}
