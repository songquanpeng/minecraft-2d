#include "archivemanager.h"
#include "ui_archivemanager.h"

ArchiveManager::ArchiveManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveManager)
{
    ui->setupUi(this);
}

ArchiveManager::~ArchiveManager()
{
    delete ui;
}
