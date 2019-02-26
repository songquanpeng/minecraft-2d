#include "lancher.h"
#include "ui_lancher.h"
#include <QStyleOption>
#include <QPainter>


Lancher::Lancher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lancher)
{
    ui->setupUi(this);
    setWindowTitle("MineCraft Lancher");
	// ¼ÓÔØÉèÖÃ
	gameSetting = new QSettings("config.ini", QSettings::IniFormat);
	loadSetting();
	if (config.backgroundMusicOn) // TODO: ÒôÀÖÑ­»·²¥·Å£»×ÔÓÉÑ¡ÔñÒôÀÖ£»ÖÇÄÜ²¥·Å±³¾°ÒôÀÖ
	{
		// ²¥·Å±³¾°ÒôÀÖ 
		backgroundMusicPlayer = new QMediaPlayer(this);
		musicList = new QMediaPlaylist(this);
		musicList->setPlaybackMode(QMediaPlaylist::Loop);
		//musicList->addMedia(QUrl::fromLocalFile("sound/subwoofer2.mp3"));
		musicList->addMedia(QUrl::fromLocalFile("sound/forest.mp3"));
		backgroundMusicPlayer->setPlaylist(musicList);
		backgroundMusicPlayer->play();
	}
}

void Lancher::loadSetting()
{
	config.backgroundMusicOn = gameSetting->value("backgroundMusicOn").toBool();
	config.difficulty = gameSetting->value("difficulty").toInt();
}

Lancher::~Lancher()
{
    delete ui;
}

void Lancher::on_aboutBtn_clicked()
{
	About *aboutDialog = new About();
	//aboutDialog->setModal(true);
    aboutDialog->show();
}

void Lancher::on_settingBtn_clicked()
{
	Setting *settingDialog = new Setting();
	//settingDialog->setModal(true);
	settingDialog->show();
}

void Lancher::on_startBtn_clicked()
{
	archiveManager = new ArchiveManager();
	archiveManager->setModal(true);
	archiveManager->show();
}


void Lancher::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}


