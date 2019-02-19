#include "archivemanager.h"
#include "ui_archivemanager.h"


ArchiveManager::ArchiveManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveManager)
{
    ui->setupUi(this);
	this->showFullScreen();
	// init data member
	archive = new QSettings("archive.ini", QSettings::IniFormat);
	world = new World();

	loadArchiveList();
	updateUi();
}

ArchiveManager::~ArchiveManager()
{
    delete ui;
}

void ArchiveManager::on_createBtn_clicked()
{
	createArchive();
	updateArchiveList();
	updateUi();
}

void ArchiveManager::loadArchiveList()
{
	int size = archive->beginReadArray("archiveList");
	for (int i = 0; i < size; ++i)
	{
		archive->setArrayIndex(i);
		ArchiveInfo archiveInfo;
		archiveInfo.id = archive->value("id").toInt();
		archiveInfo.name = archive->value("name").toString();
		archiveInfos.append(archiveInfo);
	}
	archive->endArray();
}

void ArchiveManager::updateArchiveList()
{
	// delete all old contents
	archive->clear();
	// write new contents
	archive->beginWriteArray("archiveList");
	for (int i = 0; i < archiveInfos.size(); ++i)
	{
		archive->setValue("id", archiveInfos.at(i).id);
		archive->setValue("name", archiveInfos.at(i).name);
	}
	archive->endArray();
}

void ArchiveManager::updateUi()
{
	ui->editBtn->hide();
	ui->startBtn->hide();
	// TODO
}

void ArchiveManager::createArchive()
{
	int newId = detemineId();
	// create world file
	world->createWorld(newId);
	// update archiveInfos
	ArchiveInfo archiveInfo;
	archiveInfo.id = newId;
	archiveInfo.name = archive->value("name").toString(); // TODO
	archiveInfos.append(archiveInfo);
	// update archive list
	updateArchiveList();
	// update ui
	updateUi();
}

void ArchiveManager::deleteArchive(int id)
{
	world->deleteWorld(id);
	archiveInfos.removeAt(id);
	// update archive list
	updateArchiveList();
	// update ui
	updateUi();
}

int ArchiveManager::detemineId()
{
	return archiveInfos.size();
}

void ArchiveManager::on_quitBtn_clicked()
{
	this->close();
}