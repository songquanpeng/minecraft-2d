#include "Core.h"
#include <QIcon>
#include <QListIterator>


// TODO: 玩家远程攻击
// TODO: 生物普通攻击
// TODO: 生物远程攻击
// TODO: 音效
// TODO: Setting
// TODO: 更新地图
// TODO: 保存所有生物的位置

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
	setArticleName();
}

void Core::setArticleName()
{
	articleName[BASE] = "BASE";
	articleName[GLASS] = "GLASS";
	articleName[EARTH] = "EARTH";
	articleName[STONE] = "STONE";
	articleName[WOOD] = "WOOD";
	articleName[LEAF] = "LEAF";
	articleName[WATER] = "WATER";

	articleName[SWORD] = "SWORD";
	articleName[AXE] = "AXE";
	articleName[PICK] = "PICK";
	articleName[SHOVEL] = "SHOVEL";
	articleName[BOW] = "BOW";
	articleName[ARROW] = "ARROW";
	articleName[MEAT] = "MEAT";
}


Core::~Core()
{

}

void Core::resetGame()
{
	renderTimer = startTimer(1000/FPS);
	mobsMoveTimer = startTimer(MOBS_MOVE_TIMER);
	arrowMoveTimer = startTimer(50); // TODO: arrowMoveTimer
}

void Core::startGame()
{

}

void Core::quitGame()
{
	saveMapData();
	this->close();
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
	file->close();
	return true;
}

bool Core::saveMapData()
{
	if (file->open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QTextStream input(file);
		for (int row = 0; row < WORLD_ROW; row++)
		{
			for (int col = 0; col < WORLD_COL; col++)
			{
				input << board[row][col] << " ";
			}
			input << endl;
		}
		qDebug() << "successfully save map data";
		file->close();
		return true;
	}
	return false;
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
				painter.setBrush(QBrush(QColor::fromRgb(0, 255, 127), Qt::SolidPattern));
				break;
			case WATER:
				painter.setBrush(QBrush(QColor::fromRgb(0, 0, 255), Qt::SolidPattern));
				break;
			case LEAF:
				painter.setBrush(QBrush(QColor::fromRgb(0, 139, 69), Qt::SolidPattern));
				break;
			case STONE:
				painter.setBrush(QBrush(QColor::fromRgb(156, 156, 156), Qt::SolidPattern));
				break;
			case WOOD:
				painter.setBrush(QBrush(QColor::fromRgb(139, 71, 38), Qt::SolidPattern));
				break;
			case BASE:
				painter.setBrush(QBrush(QColor::fromRgb(0, 0, 0), Qt::SolidPattern));
				break;
			case EARTH:
				painter.setBrush(QBrush(QColor::fromRgb(232, 139, 0), Qt::SolidPattern));
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

	// 渲染飞行物（如箭矢）
	renderArrows();

	// 渲染状态栏（物品栏）
	renderArticleList();

}

// 渲染物品栏
void Core::renderArticleList()
{
	QString text("");
	// 目前所持物品
	text.append("[>>> " + articleName[player->currentArticleType] + " <<<]\t");
	text.append("LEVEL<" + QString::number(player->level) + "> BLOOD<" + QString::number(player->blood)+">\t");
	// 玩家的位置
	text += ("(" + QString::number(player->realPosition.row) + " ," + QString::number(player->realPosition.col) + " )\t");
	for (int i = 0; i < MAX_ARTICLE_NUM; i++)
	{
		if (articleName[i] != NULL)
		{
			text.append(articleName[i] + "<" + QString::number(player->articleList[i]) + ">\t");
		}
	}
	QPainter painter(this);
	QPen pen;
	pen.setStyle(Qt::SolidLine);
	pen.setWidth(3);
	pen.setColor(QColor::fromRgb(148, 0, 211));
	painter.setPen(pen);
	painter.drawRect(ARTICLE_LIST_RECT);
	painter.setPen(QColor::fromRgb(255, 0, 255));
	QFont font("Geogia", 12.5, 75);
	font.setCapitalization(QFont::Capitalize);
	painter.setFont(font);
	painter.drawText(ARTICLE_LIST_RECT, Qt::AlignCenter, text);
}


// 根据相应的 实际 坐标渲染玩家与生物；每次渲染前才更新相对屏幕坐标
void Core::renderMobs()
{
	QPainter painter(this);
	// 渲染生物
	QVector<Organism*> ::iterator iter;
	for (iter = mobsList->begin(); iter != mobsList->end(); iter++)
	{
		if ((*iter) == NULL) continue;
		updateScreenPosition(*iter);
		QRectF targetPos((*iter)->positionRelativeToScreen.col, (*iter)->positionRelativeToScreen.row, 40, 40);
		painter.drawImage(targetPos, (*iter)->image);
	}


	// 渲染玩家;玩家必须最后渲染
	updateScreenPosition(player);
	QRectF targetPosition(player->positionRelativeToScreen.col, player->positionRelativeToScreen.row, 40, 40);
	painter.drawImage(targetPosition, player->image);
}

void Core::renderArrows()
{
	QPainter painter(this);
	QVector<Arrow*> ::iterator iter;
	for (iter = arrowList->begin(); iter != arrowList->end(); iter++)
	{
		if ((*iter) == NULL ) continue;
		if ((*iter)->isMoving == false) continue; // 对不移动的箭矢做隐藏处理
		updateScreenPosition(*iter);
		QRectF targetPos((*iter)->positionRelativeToScreen.col, (*iter)->positionRelativeToScreen.row, 40, 40);

		QString imageUrl;
		if ((*iter)->direction == UP)
		{
			imageUrl = ":/lancher/image/game/arrow_up.png";
		}else if ((*iter)->direction == DOWN)
		{
			imageUrl = ":/lancher/image/game/arrow_down.png";
		}
		else if ((*iter)->direction == LEFT)
		{
			imageUrl = ":/lancher/image/game/arrow_left.png";
		}
		else if ((*iter)->direction == RIGHT)
		{
			imageUrl = ":/lancher/image/game/arrow_right.png";
		}
		painter.drawImage(targetPos, QImage(imageUrl));
	}

}

void Core::removeNotMovingArrow()
{
	QVector<Arrow*> ::iterator iter;
	for (iter = arrowList->begin(); iter != arrowList->end(); iter++)
	{
		if ((*iter) == NULL || (*iter)->isMoving == false)
		{
			delete *iter;
			arrowList->erase(iter);
		}
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
		quitGame();
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
	case Qt::Key_Tab:
		player->changeCurrentHold(1);
		break;
	case Qt::Key_CapsLock:
		player->changeCurrentHold(-1);
		break;
	default:
		break;
	}
}

// 自动更新mousePoint 与 mouseGridPoint
void Core::mousePressEvent(QMouseEvent * event)
{
	mousePoint.row = (event->y() / SIZE)*SIZE;
	mousePoint.col = (event->x() / SIZE)*SIZE;
	mouseGridPoint = screenPositionToScreenGridPosition(mousePoint);
	qDebug() << "mousePoint.col " << mousePoint.col << "; mousePoint.row " << mousePoint.row;
	if (event->button() == Qt::LeftButton) 
	{
		// 判断是否是远程攻击
		if (player->currentArticleType == BOW)
		{
			shotArrow(player);
		}
		else
		{
			playerNormalAction();
		}
	}
	else if(event->button() == Qt::RightButton) // TODO: 判断玩家的行为(前往或者放置）
	{
		playerCreateCube(mouseGridPoint);
	}

}

// 远程攻击
void Core::shotArrow(Organism* shoter)
{
	int direction;
	// 首先确定鼠标点与发射者的位置
	Point shoterRealGrid = pixelToGrid(shoter->realPosition);
	Point mouseRealGrid;
	mouseRealGrid.row = mouseGridPoint.row + windowStartPoint.row;
	mouseRealGrid.col = mouseGridPoint.col + windowStartPoint.col;
	Point arrowStartRealGrid;
	if (mouseRealGrid.col < shoterRealGrid.col)
	{
		direction = LEFT;
		arrowStartRealGrid.row = shoterRealGrid.row;
		arrowStartRealGrid.col = shoterRealGrid.col - 1;

	}
	else if (mouseRealGrid.col > shoterRealGrid.col)
	{
		direction = RIGHT;
		arrowStartRealGrid.row = shoterRealGrid.row;
		arrowStartRealGrid.col = shoterRealGrid.col + 1;

	}
	else if (mouseRealGrid.row < shoterRealGrid.row)
	{
		direction = UP;
		arrowStartRealGrid.row = shoterRealGrid.row - 1;
		arrowStartRealGrid.col = shoterRealGrid.col;

	}
	else if (mouseRealGrid.row > shoterRealGrid.row)
	{
		direction = DOWN;
		arrowStartRealGrid.row = shoterRealGrid.row + 1;
		arrowStartRealGrid.col = shoterRealGrid.col;

	}
	else
	{
		direction = STAY;
		return;
	}

	qDebug() << shoter->name << " shot at direction: " << direction << " row: " << arrowStartRealGrid.row << " col: " << arrowStartRealGrid.col;
	arrowList->append(new Arrow(direction, arrowStartRealGrid));
}

// 处理箭矢的移动以及碰撞，消失
void Core::moveAllArrows()
{
	QVector<Arrow*>::iterator iter;
	for (iter = arrowList->begin(); iter != arrowList->end(); iter++)
	{
		if ((*iter) == NULL) continue;
		if (!(*iter)->isMoving) continue;

		bool isMoving = moveArrows((*iter), (*iter)->direction);
		(*iter)->isMoving = isMoving; 
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

	if (isAbleToGo(player, direction, false))
	{
		movePoint(player->realPosition, direction, player->speed); // 实际坐标已更新
	}
}

// 生物移动
void Core::moveMobs(Organism* mob, int direction) 
{
	if (isAbleToGo(mob, direction, mob->isPenetrateAble))
	{
		movePoint(mob->realPosition, direction, mob->speed);
	}
}

// 箭矢移动;不可继续移动：false
bool Core::moveArrows(Arrow* arrow, int direction)
{
	if (isArrowAbleToGo(arrow, direction, arrow->isPenetrateAble))
	{
		movePoint(arrow->realPosition, direction, arrow->speed);
		return true;
	}
	return false;
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
bool Core::isAbleToGo(Organism * mobs, int direction, bool isPenetrateAble)
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
	int cubeType = board[myGridPosition.row][myGridPosition.col];
	if (cubeType == LEAF || cubeType == STONE || cubeType == WOOD)
	{
		return false;
	}
	
	if (isPenetrateAble) //如果允许穿透，则跳过生物碰撞检查
	{
		return true;
	}
	// 检查是否有玩家阻挡
	if (mobs != player)
	{
		updateScreenPosition(player);
		if (myGridPosition == screenPositionToScreenGridPosition(player->positionRelativeToScreen))
		{
			return false;
		}
	}

	// 检查是否其他生物阻挡
	if (ENABLE_CHECK_ALL)
	{
		QVector<Organism*>::iterator iter;
		for (iter = mobsList->begin(); iter != mobsList->end(); iter++)
		{
			if (*iter == NULL) continue;
			if (mobs != (*iter))
			{
				updateScreenPosition(*iter);
				if (myGridPosition == screenPositionToScreenGridPosition((*iter)->positionRelativeToScreen))
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool Core::isArrowAbleToGo(Arrow* mobs, int direction, bool isPenetrateAble)
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
	int cubeType = board[myGridPosition.row][myGridPosition.col];
	if (cubeType == LEAF || cubeType == STONE || cubeType == WOOD)
	{
		mobs->isMoving = false;
		return false;
	}

	// 是否射中了玩家
	updateScreenPosition(player);
	if (myGridPosition == screenPositionToScreenGridPosition(player->positionRelativeToScreen))
	{
		// 击中
		player->beAttacked(mobs->attakPower);

		if (!isPenetrateAble)
		{
			mobs->isMoving = false;
			return false;
		}
	}


	QVector<Organism*>::iterator iter;
	for (iter = mobsList->begin(); iter != mobsList->end(); iter++)
	{
		if (*iter == NULL) continue;
		updateScreenPosition(*iter);
		if (myGridPosition == screenPositionToScreenGridPosition((*iter)->positionRelativeToScreen))
		{
			(*iter)->beAttacked(mobs->attakPower);
			if (!isPenetrateAble)
			{
				mobs->isMoving = false;
				if ((*iter)->isDead)
				{
					delete *iter;
					mobsList->erase(iter); // 删除后，数组会前移（？）
				}
				return false;
			}
		}
	}
	return true;
}

Point Core::pixelToGrid(Point inPixel)
{
	Point inGrid;
	inGrid.col = inPixel.col / SIZE;
	inGrid.row = inPixel.row / SIZE;
	return inGrid;
}

Point Core::screenPositionToScreenGridPosition(Point screenPosition)
{
	Point result;
	result.col = (screenPosition.col / SIZE);
	result.row = (screenPosition.row / SIZE);
	return result;
}

Point Core::screenGridToRealGrid(Point screenGrid)
{
	Point result;
	result.col = screenGrid.col + windowStartPoint.col;
	result.row = screenGrid.row + windowStartPoint.row;
	return result;
}

int Core::min(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void Core::moveAllMobs()  // 在Mobs中内置定时器以实现速度控制并按照格子行动
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
	arrowList = new QVector<Arrow*>;
	Point generatedScreenPosition;
	for (int i = 0; i < MOBS_NUMBER; i++)
	{
		generatedScreenPosition.row = (rand() % SCREEN_ROW)*SIZE;
		generatedScreenPosition.col = (rand() % SCREEN_COL)*SIZE;
		mobsList->append(new Pig(positionConvertor(generatedScreenPosition)));
	}
}

// 每次操作会更新mouseGridPoint
bool Core::isActionValid()
{
	mouseGridPoint = screenPositionToScreenGridPosition(mousePoint);
	// 判断是否是有效操作
	bool isValid = false; 
	// 需要获取玩家和操作点的屏幕格坐标
	updateScreenPosition(player);
	Point playerGridPoint = screenPositionToScreenGridPosition(player->positionRelativeToScreen);
	bool condition_1 = (player->attackRange >= abs(playerGridPoint.row - mouseGridPoint.row)) && (player->attackRange >= abs(playerGridPoint.col - mouseGridPoint.col));
	isValid = condition_1;
	if (!isValid)
	{
		qDebug() << "unvalid action, player grid position: row: " << playerGridPoint.row << " col: " << playerGridPoint.col;
		return false;
	}

	return true;
}

// 决定某方块是否可以放在某一方块上
bool Core::isCubeCanBeCreateOn(Point position)
{
	int cubeType = board[position.row][position.col];
	bool isAble = false;
	switch (player->currentArticleType)
	{
	case WOOD:
		if (cubeType == GLASS || cubeType == WATER)
		{
			isAble = true;
		}
		break;
	case GLASS:
		if (cubeType == EARTH || cubeType == WATER)
		{
			isAble = true;
		}
		break;
	case STONE:
		if (cubeType == GLASS || cubeType == WATER)
		{
			isAble = true;
		}
		break;
	case LEAF:
		if (cubeType == WOOD || cubeType == WATER)
		{
			isAble = true;
		}
		break;
	case EARTH:
		if (cubeType == BASE || cubeType == WATER)
		{
			isAble = true;
		}
		break;
	case WATER:
		if (cubeType == GLASS || cubeType == BASE)
		{
			isAble = true;
		}
		break;
	case BASE:

	default:
		isAble = false;
		break;
	}

	if (!isAble)
	{
		qDebug() << "you cannot put " << player->currentArticleType << " on point: row: " << position.row << " col: " << position.col;
		return isAble;
	}
	return isAble;
}

// 玩家进行普通操作（攻击，挖掘），位置为mousePoint
void Core::playerNormalAction()
{
	qDebug() << "Player normal operation, point: row: " << mouseGridPoint.row << " col: " << mouseGridPoint.col;

	if (!isActionValid())
	{
		return;
	}

	// 判断是否是攻击
	bool isAttack = false;
	QVector<Organism*>::iterator iter;
	for (iter=mobsList->begin();iter!=mobsList->end();iter++)
	{
		if (*iter == NULL) continue;
		updateScreenPosition(*iter);
		Point mobGridPosition = screenPositionToScreenGridPosition((*iter)->positionRelativeToScreen);
		if (mouseGridPoint == mobGridPosition)
		{
			(*iter)->beAttacked(player->finalAttackPower);
			if ((*iter)->isDead)
			{
				delete *iter;
				mobsList->erase(iter); // 删除后，数组会前移（？）
			}
			isAttack = true;
			return; // 已找到被攻击的对象，退出函数
		}
	}

	if (!isAttack) // 用户进行了合法的挖掘操作
	{
		playerMining(mouseGridPoint);
	}
}

void Core::playerMining(Point miningPoint)
{
	Point realMiningPoint = screenGridToRealGrid(miningPoint);
	qDebug() << "player mine at row: " << miningPoint.row << " col: " << miningPoint.col;
	unsigned short* targetCube = &board[realMiningPoint.row][realMiningPoint.col];
	player->articleList[*targetCube] += 1; // 增加玩家物品栏储备
	switch (*targetCube)
	{
	case LEAF:
		*targetCube = WOOD;
		break;
	case STONE:
		*targetCube = GLASS;
		break;
	case WOOD:
		*targetCube = GLASS;
		break;
	case GLASS:
		*targetCube = EARTH;
		break;
	case EARTH:
		*targetCube = BASE;
		break;
	default:
		break;
	}
}

// 接收参数的单位为格
void Core::playerCreateCube(Point createPoint)
{

	if (!isActionValid())
	{
		return;
	}

	if (!isCubeCanBeCreateOn(createPoint))
	{
		return;
	}

	int* cubeNumber = &(player->articleList[player->currentArticleType]);
	if ((*cubeNumber) <= 0)
	{
		qDebug() << "no enough such type material: " << player->currentArticleType;
		return;
	}
	else
	{
		(*cubeNumber)--;
	}
	board[createPoint.row][createPoint.col] = player->currentArticleType;
	qDebug()<<"player create cube: "<< player->currentArticleType << " on point: row: " << createPoint.row << " col: " << createPoint.col;
}

// 更新所有生物（包括玩家）的状态（血量，是否死亡）
void Core::adjustAllMobsStatus()
{

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
		moveAllMobs(); // 当前正常启用
		adjustAllMobsStatus(); // 目前弃用
	}
	if (event->timerId() == arrowMoveTimer)
	{
		// TODO: 删除无用的箭矢
		// removeNotMovingArrow();  
		moveAllArrows();
	}

}
