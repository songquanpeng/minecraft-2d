#include "archivemanager.h"
#include "ui_archivemanager.h"

ArchiveManager::ArchiveManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveManager)
{
    ui->setupUi(this);
	this->showFullScreen();
	ui->editBtn->hide();
	ui->startBtn->hide();
}

ArchiveManager::~ArchiveManager()
{
    delete ui;
}

void ArchiveManager::on_createBtn_clicked()
{

}

void ArchiveManager::on_quitBtn_clicked()
{
	this->close();
}