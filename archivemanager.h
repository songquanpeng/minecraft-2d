#ifndef ARCHIVEMANAGER_H
#define ARCHIVEMANAGER_H

#include <QDialog>

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
};

#endif // ARCHIVEMANAGER_H
