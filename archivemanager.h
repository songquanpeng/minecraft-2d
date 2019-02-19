#ifndef ARCHIVEMANAGER_H
#define ARCHIVEMANAGER_H

#include <QDialog>
#include <QSettings>
#include "World.h"
#include "worldeditdialog.h"

namespace Ui {
class ArchiveManager;
}


class ArchiveManager : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveManager(QWidget *parent = nullptr);
    ~ArchiveManager();
	QSettings *archive;
	World *world;

	int currentArchiveId;

	void startGame();
	void resetGame();
	void renameGame();
	void updateUi();

private:
    Ui::ArchiveManager *ui;


private slots:
	void on_quitBtn_clicked();
	void on_renameBtn_clicked();
	void on_resetBtn_clicked();
	void on_startBtn_clicked();
	void on_spinBox_valueChanged(int value);
};

#endif // ARCHIVEMANAGER_H
