#include "worldeditdialog.h"
#include "ui_worldeditdialog.h"

WorldEditDialog::WorldEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorldEditDialog)
{
    ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
}

WorldEditDialog::~WorldEditDialog()
{
    delete ui;
}

void WorldEditDialog::on_deleteBtn_clicked()
{

}

void WorldEditDialog::on_okBtn_clicked()
{
	QString str = ui->lineEdit->text();
	if (str != "")
	{
		emit sendData(str);
	}
	this->close();
}