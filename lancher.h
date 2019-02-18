#ifndef LANCHER_H
#define LANCHER_H

#include <QWidget>
#include <QPushButton>
#include "about.h"

namespace Ui {
class Lancher;
}

class Lancher : public QWidget
{
    Q_OBJECT

public:
    explicit Lancher(QWidget *parent = nullptr);
    ~Lancher();
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::Lancher *ui;
private slots:
    // 按照以下命名方式对槽函数进行命名
    void on_aboutBtn_clicked();
};

#endif // LANCHER_H
