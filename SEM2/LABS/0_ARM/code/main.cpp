#include "QtARM.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtARM w;
    w.show();
    return a.exec();
}
