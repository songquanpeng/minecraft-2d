#include "Core.h"
#include <QIcon>



Core::Core(QString archivePath)
{
	this->showFullScreen();
	this->setWindowIcon(QIcon(":lancher/image/icon.png"));
	path = archivePath;
	file = new QFile(path+"/map.txt");
	loadMapData();
	resetGame();
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
	for (int row = 0; row < WORLD_ROW; row++)
	{
		for (int col = 0; col < WORLD_COL; col++)
		{
			board[row][col] = (unsigned short int)output.read(1).toInt();
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
			if (board[row][col] < 5)
			{
				painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
				painter.drawRect(col*SIZE, row*SIZE, SIZE, SIZE);
			}
			else if(board[row][col] >= 5)
			{
				painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
				painter.drawRect(col*SIZE, row*SIZE, SIZE, SIZE); 
			}
		}
	}
}

void Core::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Up:
		break;
	case Qt::Key_Down:
		break;
	case Qt::Key_Left:
		break;
	case Qt::Key_Right:
		break;
	case Qt::Key_Space:
		break;
	default:
		break;
	}
}

void Core::timerEvent(QTimerEvent *event)
{

	//Ë¢ÐÂ»­Ãæ
	if (event->timerId() == renderTimer)
		update();
}
