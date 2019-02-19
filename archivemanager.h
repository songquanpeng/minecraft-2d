#ifndef ARCHIVEMANAGER_H
#define ARCHIVEMANAGER_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class ArchiveManager;
}

class ArchiveManager : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveManager(QWidget *parent = nullptr);
    ~ArchiveManager();

private:
    Ui::ArchiveManager *ui;
private slots:
	void on_createBtn_clicked();
	void on_quitBtn_clicked();

};

#endif // ARCHIVEMANAGER_H
