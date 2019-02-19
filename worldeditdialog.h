#ifndef WORLDEDITDIALOG_H
#define WORLDEDITDIALOG_H

#include <QDialog>

namespace Ui {
class WorldEditDialog;
}

class WorldEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorldEditDialog(QWidget *parent = nullptr);
    ~WorldEditDialog();

private:
    Ui::WorldEditDialog *ui;

private slots:
	void on_deleteBtn_clicked();
	void on_okBtn_clicked();

signals:
	void sendData(QString);
};

#endif // WORLDEDITDIALOG_H
