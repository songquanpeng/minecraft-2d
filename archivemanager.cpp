#include "archivemanager.h"
#include "ui_archivemanager.h"
#include <QMessageBox>


ArchiveManager::ArchiveManager(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::ArchiveManager)
{
	ui->setupUi(this);

	this->showFullScreen();
	this->setAttribute(Qt::WA_DeleteOnClose, true);
	this->setWindowTitle("Archive Manager");
	archive = new QSettings("archive.ini", QSettings::IniFormat);
	world = new World();
	currentArchiveId = 0;
	updateUi();
}

ArchiveManager::~ArchiveManager()
{
    delete ui;
}

bool ArchiveManager::startGame()
{
	bool isSuccess = world->startGame(currentArchiveId);
	return isSuccess;
}

void ArchiveManager::resetGame()
{
	world->resetGame(currentArchiveId);
}

void ArchiveManager::renameGame()
{
	QString newName = ui->lineEdit->text();
	if (newName != "")
	{
		archive->setValue(QString::number(currentArchiveId), newName);
	}
}

void ArchiveManager::updateUi()
{
	ui->lineEdit->setText(archive->value(QString::number(currentArchiveId)).toString());
}


void ArchiveManager::on_quitBtn_clicked()
{
	this->close();
}

void ArchiveManager::on_renameBtn_clicked()
{
	renameGame();
}

void ArchiveManager::on_resetBtn_clicked()
{
	resetGame();
}

void ArchiveManager::on_startBtn_clicked()
{
	startGame();
}

void ArchiveManager::on_spinBox_valueChanged(int value)
{
	currentArchiveId = value;
	updateUi();
}