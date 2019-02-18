#include "lancher.h"
#include "ui_lancher.h"
#include <QStyleOption>
#include <QPainter>

Lancher::Lancher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lancher)
{
    ui->setupUi(this);

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

