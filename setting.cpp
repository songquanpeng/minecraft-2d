#include "setting.h"
#include "ui_setting.h"
#include <QMouseEvent>
#include <QDebug>
#include <QMessageBox>


Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setWindowTitle("Setting");
	this->setAttribute(Qt::WA_DeleteOnClose, true);

	setting = new QSettings("config.ini", QSettings::IniFormat);
	// 开始读取配置文件
	loadSetting();
}

Setting::~Setting()
{
    delete ui;
}

void Setting::loadSetting()
{
	config.backgroundMusicOn = setting->value("backgroundMusicOn").toBool();
	config.difficulty = setting->value("difficulty").toInt();
	config.number = setting->value("number").toInt();
	config.interval = setting->value("interval").toInt();
	config.fps = setting->value("fps").toInt();

	ui->musicCheckBox->setChecked(config.backgroundMusicOn);
	ui->numberSpinBox->setValue(config.number);
	ui->intervalSpinBox->setValue(config.interval);
	ui->fpsSpinBox->setValue(config.fps);
	// load difficulty setting
	if (config.difficulty == Pease) {
		ui->peace->setChecked(true);
	}
	else if (config.difficulty == Easy) {
		ui->easy->setChecked(true);
	}
	else if (config.difficulty == Normal) {
		ui->normal->setChecked(true);
	}
	else if (config.difficulty == Difficult) {
		ui->difficult->setChecked(true);
	}
}

void Setting::updateSetting()
{
	config.backgroundMusicOn = ui->musicCheckBox->isChecked();
	config.number = ui->numberSpinBox->value();
	config.fps = ui->fpsSpinBox->value();
	config.interval = ui->intervalSpinBox->value();

	// update difficulty setting
	if (ui->peace->isChecked()){
		config.difficulty = Pease;
	}
	else if (ui->easy->isChecked()) {
		config.difficulty = Easy;
	}
	else if (ui->normal->isChecked()) {
		config.difficulty = Normal;
	}
	else if (ui->difficult->isChecked()) {
		config.difficulty = Difficult;
	}

	setting->setValue("difficulty", config.difficulty);
	setting->setValue("backgroundMusicOn", config.backgroundMusicOn);
	setting->setValue("interval", config.interval);
	setting->setValue("number", config.number);
	setting->setValue("fps", config.fps);

}

void Setting::resetSetting()
{
	ui->musicCheckBox->setChecked(true);
	ui->normal->setChecked(true);
	ui->numberSpinBox->setValue(20);
	ui->intervalSpinBox->setValue(10);
	ui->fpsSpinBox->setValue(60);

	updateSetting();
}

void Setting::on_okBtn_clicked()
{
	updateSetting();
	// QMessageBox::information(this, "Done", "OK");
	QDialog::close();

}

void Setting::on_resetBtn_clicked()
{
	resetSetting();
}

void Setting::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		mouseMoveing = true;
		lastMousePosition = event->globalPos();
	}
}

void Setting::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons().testFlag(Qt::LeftButton) && mouseMoveing)
	{
		this->move(this->pos() + (event->globalPos() - lastMousePosition));
		lastMousePosition = event->globalPos();
	}
}

void Setting::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		mouseMoveing = false;
	}
}
