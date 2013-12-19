#include <QtGui/QApplication>
#include "mapform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapForm w;
    w.show();

    return a.exec();
}
