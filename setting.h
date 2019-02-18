#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class Setting;
}

const int Pease = 0;
const int Easy = 1;
const int Normal = 2;
const int Difficult = 3;


struct Config
{
	int difficulty;
	bool backgroundMusicOn;
};

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();
	void loadSetting();
	void updateSetting();
	void resetSetting();
	Config config;
private:
    Ui::Setting *ui;
	QSettings *setting;
private slots:
	void on_okBtn_clicked();
	void on_resetBtn_clicked();
protected:
	// 实现窗体的可拖动
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	bool mouseMoveing;
	QPoint lastMousePosition;
};

#endif // SETTING_H
