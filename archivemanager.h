#ifndef ARCHIVEMANAGER_H
#define ARCHIVEMANAGER_H

#include <QDialog>
#include <QSettings>
#include "World.h"
#include "worldeditdialog.h"

namespace Ui {
class ArchiveManager;
}

struct ArchiveInfo
{
	QString name;
	int id;
};

class ArchiveManager : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveManager(QWidget *parent = nullptr);
    ~ArchiveManager();
	QSettings *archive;
	int currentArchiveId;
	QList<ArchiveInfo> archiveInfos;
	World *world;

private:
    Ui::ArchiveManager *ui;
	void loadArchiveList();
	void updateArchiveList();
	void updateUi();

	void createArchive();  // create archive and modify archiveInfos
	void deleteArchive(int id);  // delete archive and modify archiveInfos
	int detemineId();

private slots:
	void on_createBtn_clicked();
	void on_quitBtn_clicked();
	void on_editBtn_clicked();
	void receiveData(QString data);
};

#endif // ARCHIVEMANAGER_H
