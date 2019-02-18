#include "lancher.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lancher w;
    w.show();

    return a.exec();
}
