#include "sammainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SamMainWindow w;
    w.show();
    return a.exec();
}
