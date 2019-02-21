#include "Core.h"
#include <QIcon>
#include <QListIterator>



Core::Core(QString archivePath)
{
	this->showFullScreen();
	this->setWindowIcon(QIcon(":lancher/image/icon.png"));
	path = archivePath;
	file = new QFile(path+"/map.txt");
	loadMapData();
	resetGame();
	windowStartPoint.row = 0;
	windowStartPoint.col = 0;
	player.realPosition = positionConvertor(player.positionRelativeToScreen);
	mobsList = new QVector<Organism>(MOBS_NUMBER);
}


Core::~Core()
{

}

void Core::resetGame()
{
	renderTimer = startTimer(1000/FPS);
}

void Core::startGame()
{

}

bool Core::loadMapData()
{
	if (!file->open(QIODevice::ReadWrite | QIODevice::Text)) {
		return false;
	}
	QTextStream output(file);
	QStringList line;
	for (int row = 0; row < WORLD_ROW; row++)
	{
		line = output.readLine().split(" ");
		QListIterator<QString> listIterator(line);
		for (int col = 0; col < WORLD_COL; col++)
		{
			board[row][col] = (unsigned short int)listIterator.next().toInt();
		}
	}
	return true;
}

void Core::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);

	for (int row = 0; row < SCREEN_ROW; ++row)
	{
		for (int col = 0; col < SCREEN_COL; ++col) // 渲染时依据绝对坐标
		{
			switch (board[windowStartPoint.row + row][windowStartPoint.col + col])
			{
			case GLASS:
				painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));

				break;
			case WATER:
				painter.setBrush(QBrush(Qt::blue, Qt::SolidPattern));

				break;
			case LEAF:
				painter.setBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));

				break;
			case STONE:
				painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));

				break;
			default:
				break;
			}
			painter.drawRect(col*SIZE, row*SIZE, SIZE, SIZE);
		}
	}

	renderMobs();
}

// 根据相应的坐标渲染玩家与生物
void Core::renderMobs()
{
	QPainter painter(this);
	// 渲染玩家
	player.positionRelativeToScreen = absolutePositionConvertor(player.realPosition);
	QRectF targetPosition(player.positionRelativeToScreen.col, player.positionRelativeToScreen.row, 40, 40); // TODO: 玩家初始位置的确定
	QImage playerImage(":/lancher/image/game/steven.png");
	painter.drawImage(targetPosition, playerImage);

}

void Core::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Up:
		moveWindow(UP);
		break;
	case Qt::Key_Down:
		moveWindow(DOWN);
		break;
	case Qt::Key_Left:
		moveWindow(LEFT);
		break;
	case Qt::Key_Right:
		moveWindow(RIGHT);
		break;
	case Qt::Key_Escape:
		this->close();
		break;
	case Qt::Key_W:
		movePlayer(UP);
		break;
	case Qt::Key_S:
		movePlayer(DOWN);
		break;
	case Qt::Key_A:
		movePlayer(LEFT);
		break;
	case Qt::Key_D:
		movePlayer(RIGHT);
		break;

	default:
		break;
	}
}

// 根据方向操作screen显示的部位；防止越界
void Core::moveWindow(int direction, int moveStep)
{
	switch (direction)
	{
	case UP:
		windowStartPoint.row -= moveStep;
		break;
	case DOWN:
		windowStartPoint.row += moveStep;
		break;
	case LEFT:
		windowStartPoint.col -= moveStep;
		break;
	case RIGHT:
		windowStartPoint.col += moveStep;
		break;
	default:
		break;
	}
	if (windowStartPoint.col < 0) windowStartPoint.col = 0;
	if (windowStartPoint.row < 0) windowStartPoint.row = 0;
	if (windowStartPoint.col >= WORLD_COL - SCREEN_COL) windowStartPoint.col = WORLD_COL - SCREEN_COL;
	if (windowStartPoint.row >= WORLD_ROW - SCREEN_ROW) windowStartPoint.row = WORLD_ROW - SCREEN_ROW;
}

void Core::moveWindow(int direction)
{
	moveWindow(direction, WINDOW_MOVE_STEP);
}

// 玩家移动
void Core::movePlayer(int direction) // TODO：当玩家移动到边缘时要控制窗口移动
{
	movePoint(player.realPosition, direction, player.speed);
	//movePoint(player.realPosition, direction, 4);

}

// 确保不超出真实地图边界；单位：像素
void Core::movePoint(Point& point, int direction, int moveDistance) 
{
	switch (direction)
	{
	case UP:
		point.row -= moveDistance;
		break;
	case DOWN:
		point.row += moveDistance;
		break;
	case LEFT:
		point.col -= moveDistance;
		break;
	case RIGHT:
		point.col += moveDistance;
		break;
	default:
		break;
	}
	if (point.col < 0) point.col = 0;
	if (point.row < 0) point.row = 0;
	if (point.col >= (WORLD_COL)*SIZE) point.col = (WORLD_COL)*SIZE;
	if (point.row >= (WORLD_ROW)*SIZE) point.row = (WORLD_ROW)*SIZE;
}

// 以格为单位，非像素
Point Core::positionConvertor(Point screenPostion)
{
	Point realPostion;
	realPostion.row = (screenPostion.row + windowStartPoint.row)*SIZE;
	realPostion.col = (screenPostion.col + windowStartPoint.col)*SIZE;
	return realPostion;
}

// 绝对坐标-->屏幕坐标; 注意：转换后可能并不在屏幕内
Point Core::absolutePositionConvertor(Point absolutePosition)
{
	Point screenPosition;
	screenPosition.row = absolutePosition.row - windowStartPoint.row*SIZE;
	screenPosition.col = absolutePosition.col - windowStartPoint.col*SIZE;
	return screenPosition;
}

void Core::timerEvent(QTimerEvent *event)
{

	//刷新画面
	if (event->timerId() == renderTimer)
		update();
}
