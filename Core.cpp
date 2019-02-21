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
	player = new Player();
	player->realPosition = positionConvertor(player->positionRelativeToScreen);
	generateMobs();
	mousePoint.col = WORLD_COL*SIZE;
	mousePoint.row = WORLD_ROW*SIZE;
}


Core::~Core()
{

}

void Core::resetGame()
{
	renderTimer = startTimer(1000/FPS);
	mobsMoveTimer = startTimer(MOBS_MOVE_TIMER);
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

	// 渲染环境
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
	// 渲染鼠标所指点
	painter.setBrush(Qt::NoBrush);
	QPen pen;
	pen.setStyle(Qt::DotLine);
	pen.setWidth(3);
	pen.setColor(Qt::red);
	painter.setPen(pen);
	painter.drawRect(mousePoint.col, mousePoint.row, SIZE, SIZE);
	// 渲染生物（包括玩家）
	renderMobs();
}

// 根据相应的 实际 坐标渲染玩家与生物；每次渲染前才更新相对屏幕坐标
void Core::renderMobs()
{
	QPainter painter(this);
	// 渲染玩家
	updateScreenPosition(player);
	QRectF targetPosition(player->positionRelativeToScreen.col, player->positionRelativeToScreen.row, 40, 40);
	painter.drawImage(targetPosition, player->image);

	// 渲染生物
	QVector<Organism*> ::iterator iter;
	for (iter = mobsList->begin(); iter != mobsList->end(); iter++)
	{
		if ((*iter) == NULL) continue;
		updateScreenPosition(*iter);
		QRectF targetPos((*iter)->positionRelativeToScreen.col, (*iter)->positionRelativeToScreen.row, 40, 40);
		painter.drawImage(targetPos, (*iter)->image);
	}

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

void Core::mousePressEvent(QMouseEvent * event)
{
	mousePoint.row = (event->y() / SIZE)*SIZE;
	mousePoint.col = (event->x() / SIZE)*SIZE;
	
	if (event->button() == Qt::LeftButton)
	{

	}

}

// 根据方向操作screen显示的部位；防止越界；此函数仅更新 windowStartPoint
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
void Core::movePlayer(int direction) 
{
	if (isMobNearScreenBorder(player, direction))
	{
		moveWindow(direction, SCREEN_MOVE_DISTANCE);
	}

	if (isAbleToGo(player, direction))
	{
		movePoint(player->realPosition, direction, player->speed); // 实际坐标已更新
	}
}

// 生物移动
void Core::moveMobs(Organism* mob, int direction) 
{
	if (isAbleToGo(mob, direction))
	{
		movePoint(mob->realPosition, direction, mob->speed);
	}
}

// 每次检查都会更新其屏幕坐标; 玩家若正在靠近，则置true
bool Core::isMobNearScreenBorder(Organism * mobs, int direction)
{
	// 确保屏幕坐标正确
	updateScreenPosition(mobs);
	bool colMin = mobs->positionRelativeToScreen.col <= DISTANCE_TO_SCREEN_BORDER;
	bool colMax = mobs->positionRelativeToScreen.col + DISTANCE_TO_SCREEN_BORDER >= SCREEN_COL * SIZE;
	bool rowMin = mobs->positionRelativeToScreen.row <= DISTANCE_TO_SCREEN_BORDER;
	bool rowMax = mobs->positionRelativeToScreen.row + DISTANCE_TO_SCREEN_BORDER >= SCREEN_ROW * SIZE;

	if ((direction == UP && rowMin) || (direction == DOWN && rowMax) || (direction == LEFT && colMin) || direction == RIGHT && colMax)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 需要准确的实际坐标
bool Core::isAbleToGo(Organism * mobs, int direction)
{
	Point myGridPosition = pixelToGrid(mobs->realPosition);
	switch (direction)
	{
	case UP:
		myGridPosition.row -= 1;
		break;
	case DOWN:
		myGridPosition.row += 1;
		break;
	case LEFT:
		myGridPosition.col -= 1;
		break;
	case RIGHT:
		myGridPosition.col += 1;
		break;
	default:
		break;
	}
	// 检查是否越界
	if (myGridPosition.row < 0 || myGridPosition.col < 0 || myGridPosition.col >= WORLD_COL || myGridPosition.row >= WORLD_ROW)
	{
		return false;
	}

	// 检查是否是可以通过的方块
	if (board[myGridPosition.row][myGridPosition.col] == LEAF || board[myGridPosition.row][myGridPosition.col] == STONE)
	{
		return false;
	}
	return true;;
}

Point Core::pixelToGrid(Point inPixel)
{
	Point inGrid;
	inGrid.col = inPixel.col / SIZE;
	inGrid.row = inPixel.row / SIZE;
	return inGrid;
}

void Core::moveAllMobs()
{
	QVector<Organism*> ::iterator iter;
	for (iter = mobsList->begin(); iter != mobsList->end(); iter++)
	{
		if ((*iter) == NULL) continue;
		moveMobs(*iter, (*iter)->desiredDirection());
	}
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
	case STAY:
		break;
	default:
		break;
	}
	if (point.col < 0) point.col = 0;
	if (point.row < 0) point.row = 0;
	if (point.col >= (WORLD_COL)*SIZE) point.col = (WORLD_COL - 1)*SIZE;
	if (point.row >= (WORLD_ROW)*SIZE) point.row = (WORLD_ROW - 1)*SIZE;
}

// 生成怪物
void Core::generateMobs()
{
	srand(static_cast<unsigned int>(time(0)));
	mobsList = new QVector<Organism*>; 
	Point generatedScreenPosition;
	for (int i = 0; i < MOBS_NUMBER; i++)
	{
		generatedScreenPosition.row = (rand() % SCREEN_ROW)*SIZE;
		generatedScreenPosition.col = (rand() % SCREEN_COL)*SIZE;
		mobsList->append(new Pig(positionConvertor(generatedScreenPosition)));
	}
}

// 以像素为单位，非格；屏幕坐标-->绝对坐标
Point Core::positionConvertor(Point screenPostion)
{
	Point realPostion;
	realPostion.row = screenPostion.row + windowStartPoint.row*SIZE;
	realPostion.col = screenPostion.col + windowStartPoint.col*SIZE;
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

// 根据其实际坐标更新其屏幕坐标
void Core::updateScreenPosition(Organism * mobs)
{
	mobs->positionRelativeToScreen = absolutePositionConvertor(mobs->realPosition);
}


void Core::timerEvent(QTimerEvent *event)
{

	//刷新画面
	if (event->timerId() == renderTimer)
	{
		update();
		
	}
	if (event->timerId() == mobsMoveTimer)
	{
		// 生物移动
		moveAllMobs();
	}
}
