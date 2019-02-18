#ifndef LANCHER_H
#define LANCHER_H

#include <QWidget>

namespace Ui {
class Lancher;
}

class Lancher : public QWidget
{
    Q_OBJECT

public:
    explicit Lancher(QWidget *parent = nullptr);
    ~Lancher();
//    void paintEvent(QPaintEvent *event);
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::Lancher *ui;
};

#endif // LANCHER_H
