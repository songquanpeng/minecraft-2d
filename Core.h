#pragma once
#include <qwidget.h>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QPaintEvent>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
#include <QPainter>

struct Point
{
	int row;
	int col;
};

const int WORLD_ROW = 270;
const int WORLD_COL = 480;
const int SIZE = 40;
const int SCREEN_ROW = 27;
const int SCREEN_COL = 48;
const int RIVER_WIDTH = 7;
const int RIVER_PROBABILITY = 9;
const int STONE_PROBABILITY = 2;
const int WOOD_PROBABILITY = 2;
const int EARTH_PROBABILITY = 6;

const int BASE = 0;
const int GLASS = 1;
const int EARTH = 2;
const int STONE = 3;
const int WOOD = 4;
const int LEAF = 5;
const int WATER = 6;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

const int WINDOW_MOVE_STEP = 5;
class Core :
	public QWidget
{
public:
	Core(QString archivePath);
	~Core();
	QString path;
	QFile *file;
	unsigned short int board[WORLD_ROW][WORLD_COL]; // 行，列


	void resetGame();
	void startGame();
	bool loadMapData();
	virtual void paintEvent(QPaintEvent *event); //场景刷新
	virtual void timerEvent(QTimerEvent *event); //定时器事件
	virtual void keyPressEvent(QKeyEvent *event); //键盘响应
private:
	int renderTimer;
	void moveWindow(int direction);
	Point windowStartPoint;
};

