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
//    QPushButton *aboutBtn;
private slots:
    void on_aboutBtn_clicked();
};

#endif // LANCHER_H
