#include "QtCmake.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCmake w;
    w.show();
    return a.exec();
}
