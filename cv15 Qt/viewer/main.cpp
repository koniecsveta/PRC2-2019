#include <QApplication>
#include "viewer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Viewer v;
    v.show();
    return a.exec();
}
