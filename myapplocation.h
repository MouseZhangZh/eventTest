#ifndef MYAPPLOCATION_H
#define MYAPPLOCATION_H

#include <QApplication>
#include <QTime>
#include <QDebug>

#include "mainwindow.h"

#define __P__ qDebug() << "----------------------"; \
qDebug() << __PRETTY_FUNCTION__ << obj << event; \
qDebug() << QTime::currentTime();
class MyApplocation : public QApplication
{
public:
    MyApplocation(int &argc, char **argv);
    virtual bool notify(QObject *obj, QEvent *event) override {
//        printf("Notify!\n");
        __P__
        return QApplication::notify(obj, event);
//        return false;
    }
};

#endif // MYAPPLOCATION_H
