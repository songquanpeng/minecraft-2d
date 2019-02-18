#ifndef LANCHER_H
#define LANCHER_H

#include <QWidget>
#include <QPushButton>
#include <QMediaPlayer>
#include <QSettings>
#include "about.h"
#include "setting.h"
#include "archivemanager.h"

namespace Ui {
class Lancher;
}

class Lancher : public QWidget
{
    Q_OBJECT

public:
    explicit Lancher(QWidget *parent = nullptr);
	QSettings *gameSetting;
	Config config;
	void loadSetting();
    ~Lancher();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::Lancher *ui;
    QMediaPlayer *backgroundMusicPlayer;
	ArchiveManager *archiveManager;
	//About *aboutDialog;
	//Setting *settingDialog;
private slots:
    // 按照以下命名方式对槽函数进行命名
    void on_aboutBtn_clicked();
	void on_settingBtn_clicked();
	void on_startBtn_clicked();

};

#endif // LANCHER_H
