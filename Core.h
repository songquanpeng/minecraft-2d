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
#include <QColor>
#include "Constant.h"
#include "Organism.h"
#include "Player.h"
#include "Pig.h"
#include "Skeleton.h"
#include "Arrow.h"

class Core :
	public QWidget
{
public:
	Core(QString archivePath);
	~Core();
	QString path;
	QFile *file;
	unsigned short int board[WORLD_ROW][WORLD_COL]; // 行，列
	   
	QString articleName[MAX_ARTICLE_NUM];
	void resetGame();
	void startGame();
	void quitGame();
	bool loadMapData();
	bool saveMapData();
	virtual void paintEvent(QPaintEvent *event); //场景刷新
	virtual void timerEvent(QTimerEvent *event); //定时器事件
	virtual void keyPressEvent(QKeyEvent *event); //键盘响应
	void mousePressEvent(QMouseEvent *event);
	// virtual void keyReleaseEvent(QKeyEvent *event); //键盘响应

private:
	void shotArrow(Organism* shoter);
	void moveAllArrows(); 
	int renderTimer;
	int mobsMoveTimer;
	int arrowMoveTimer;
	Point mousePoint; // 单位像素
	Point mouseGridPoint; // 指针鼠标位置，单位：格
	Player *player;
	QVector<Organism*> *mobsList; 
	QVector<Arrow*> *arrowList;
	Point windowStartPoint; // 单位：格
	void setArticleName();
	void renderMobs();
	void renderArrows();
	void removeNotMovingArrow();
	void renderArticleList();
	void moveWindow(int direction, int moveStep); 
	void moveWindow(int direction);
	void movePlayer(int direction);
	void moveMobs(Organism* mob, int direction);
	bool moveArrows(Arrow* arrow, int direction);
	void moveAllMobs();
	void movePoint(Point& point, int direction, int moveDistance);
	void generateMobs();
	void playerNormalAction();
	void playerMining(Point miningPoint);
	void playerCreateCube(Point createPoint);
	void adjustAllMobsStatus();
	Point positionConvertor(Point screenPostion);
	Point absolutePositionConvertor(Point absolutePosition);
	void updateScreenPosition(Organism* mobs);
	bool isMobNearScreenBorder(Organism* mobs, int direction);
	bool isAbleToGo(Organism* mobs, int direction, bool isPenetrateAble);
	bool isArrowAbleToGo(Arrow* mobs, int direction, bool isPenetrateAble);
	bool isActionValid();
	bool isCubeCanBeCreateOn(Point position);
	Point pixelToGrid(Point inPixel);
	Point screenPositionToScreenGridPosition(Point screenPosition);
	Point screenGridToRealGrid(Point screenGrid);
	int min(int a, int b);
};

