#pragma once
#include <qwidget.h>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QVector>
#include "Constant.h"
#include "Organism.h"
#include "Player.h"
#include "Pig.h"

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
	void mousePressEvent(QMouseEvent *event);
	// virtual void keyReleaseEvent(QKeyEvent *event); //键盘响应

private:
	int renderTimer;
	int mobsMoveTimer;
	Point mousePoint; // 单位像素
	Point mouseGridPoint; // 单位格
	Player *player;
	QVector<Organism*> *mobsList; 
	Point windowStartPoint;
	void renderMobs(); 
	void moveWindow(int direction, int moveStep); 
	void moveWindow(int direction);
	void movePlayer(int direction);
	void moveMobs(Organism* mob, int direction);
	void moveAllMobs();
	void movePoint(Point& point, int direction, int moveDistance);
	void generateMobs();
	void playerNormalAttack();
	void adjustAllMobsStatus();
	Point positionConvertor(Point screenPostion);
	Point absolutePositionConvertor(Point absolutePosition);
	void updateScreenPosition(Organism* mobs);
	bool isMobNearScreenBorder(Organism* mobs, int direction);
	bool isAbleToGo(Organism* mobs, int direction);
	Point pixelToGrid(Point inPixel);
	Point screenPositionToScreenGridPosition(Point screenPosition);
	int min(int a, int b);
};

