#include "lancher.h"
#include "ui_lancher.h"
#include <QStyleOption>
#include <QPainter>


Lancher::Lancher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lancher)
{
    ui->setupUi(this);
    setWindowTitle("MineCraft");

    backgroundMusicPlayer = new QMediaPlayer(this);
//    connect(backgroundMusicPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    backgroundMusicPlayer->setMedia(QUrl::fromLocalFile("sound/forest.mp3"));
    backgroundMusicPlayer->play();
}

Lancher::~Lancher()
{
    delete ui;
}

void Lancher::on_aboutBtn_clicked()
{
    About *aboutDialog = new About();
    aboutDialog->show();
}


void Lancher::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

