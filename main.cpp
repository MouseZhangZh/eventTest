#include <QApplication>

#include "mainwindow.h"
#include "myapplocation.h"


int main(int argc, char *argv[])
{
    MyApplocation a(argc, argv);
    MainWindow w;
    w.show();
    a.installNativeEventFilter(&w);
    a.installEventFilter(&w);
    return a.exec();
}
