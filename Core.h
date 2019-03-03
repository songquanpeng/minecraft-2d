#pragma once
#include <qwidget.h>
#include <QString>
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QIcon>
#include <QListIterator>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QVector>
#include <QColor>
#include <QMediaPlayer>
#include "Constant.h"
#include "Organism.h"
#include "Player.h"
#include "Pig.h"
#include "Skeleton.h"
#include "Arrow.h"
#include "Zombie.h"
#include "Cow.h"
#include "Sheep.h"

class Core :
	public QWidget
{
public:
	Core(QString archivePath);
	~Core();
	QString path;
	QFile *file;
	unsigned short int board[WORLD_ROW][WORLD_COL]; // 行，列
	int mobsCount;

	QString articleName[MAX_ARTICLE_NUM];
	void resetGame();
	void startGame();
	void pauseGame();
	void quitGame();
	void playerRebrith();
	bool loadMapData();
	bool saveMapData();
	virtual void paintEvent(QPaintEvent *event); //场景刷新
	virtual void timerEvent(QTimerEvent *event); //定时器事件
	virtual void keyPressEvent(QKeyEvent *event); //键盘响应
	void mousePressEvent(QMouseEvent *event);
	// virtual void keyReleaseEvent(QKeyEvent *event); //键盘响应
	QMediaPlayer soundPlayer;
	void playSound(Organism* mob);
	Point birthPoint;

private:
	int mobChasingRange;
	int zombieAttackPower;
	int skeletonAttackPower;
	Config config;
	void loadSetting();
	void addNewMobs();
	void initPlayer();
	void updatePlayer();
	bool isGameOnGoing;
	void mobAttack(Organism* attacker);
	int mobChasingPlayer(Organism* mob);
	void moveAllArrows(); 
	int renderTimer;
	int mobsMoveTimer;
	int arrowMoveTimer;
	int checkMobsNumberTimer;
	Point mousePoint; // 单位像素
	Point mouseGridPoint; // 指针鼠标位置，单位：格;注意为屏幕坐标
	Point rebirthPoint;
	Point rebirthWindow;
	Player *player;
	QVector<Organism*> *mobsList; 
	QVector<Arrow*> *arrowList;
	Point windowStartPoint; // 单位：格, 真实坐标
	void setArticleName();
	void renderMobs();
	void renderArrows();
	void removeNotMovingArrow();
	void renderArticleList();
	void moveWindow(int direction, int moveStep); 
	void moveWindow(int direction);
	bool movePlayer(int direction);
	void moveMobs(Organism* mob, int direction);
	bool moveArrows(Arrow* arrow, int direction);
	void moveAllMobs();
	void movePoint(Point& point, int direction, int moveDistance);
	void generateMobs(int number);
	void playerNormalAction();
	void playerMining(Point miningPoint);
	void playerCreateCube(Point createPoint);
	void playerGotoMousePoint();
	void adjustAllMobsStatus();

	Point positionConvertor(Point screenPostion);
	Point absolutePositionConvertor(Point absolutePosition);
	Point pixelToGrid(Point inPixel);
	Point screenPositionToScreenGridPosition(Point screenPosition);
	Point screenGridToRealGrid(Point screenGrid);

	void updateScreenPosition(Organism* mobs);

	bool isMobNearScreenBorder(Organism* mobs, int direction);
	bool isAbleToGo(Organism* mobs, int direction, bool isPenetrateAble);
	bool isArrowAbleToGo(Arrow* mobs, int direction, bool isPenetrateAble);
	bool isActionValid();
	bool isCubeCanBeCreateOn(Point position);
	bool isPointInScreen(Point position);

	int min(int a, int b);
};

