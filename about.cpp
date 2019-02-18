#include "about.h"
#include "ui_about.h"
#include <QStyleOption>
#include <QPainter>
#include <QMouseEvent>

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowTitle("About");
}

About::~About()
{
    delete ui;
}

void About::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void About::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouseMoveing = true;
        lastMousePosition = event->globalPos();
    }
}

void About::mouseMoveEvent(QMouseEvent* event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mouseMoveing)
    {
        this->move(this->pos() + (event->globalPos() - lastMousePosition));
        lastMousePosition = event->globalPos();
    }
}

void About::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouseMoveing = false;
    }
}
