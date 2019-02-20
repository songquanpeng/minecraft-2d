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
}


Core::~Core()
{

}

void Core::resetGame()
{
	renderTimer = startTimer(100);
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
		for (int col = 0; col < SCREEN_COL; ++col)
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
	default:
		break;
	}
}

void Core::renderMobs()
{

}

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

void Core::movePlayer(int direction)
{
	switch (direction)
	{
	case UP:
		windowStartPoint.row -= player.speed;
		break;
	case DOWN:
		windowStartPoint.row += player.speed;
		break;
	case LEFT:
		windowStartPoint.col -= player.speed;
		break;
	case RIGHT:
		windowStartPoint.col += player.speed;
		break;
	default:
		break;
	}

}

Point Core::positionConvertor(Point screenPostion)
{
	Point realPostion;
	realPostion.row = screenPostion.row + windowStartPoint.row;
	realPostion.col = screenPostion.col + windowStartPoint.col;
	return realPostion;
}

void Core::timerEvent(QTimerEvent *event)
{

	//Ë¢ÐÂ»­Ãæ
	if (event->timerId() == renderTimer)
		update();
}
