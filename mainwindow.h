#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <xcb/xcb.h>
#include <QAbstractNativeEventFilter>
#include <QMainWindow>
#include <QEvent>
#include <QTime>
#include <QDebug>

#define __P__ qDebug() << "----------------------"; \
qDebug(__PRETTY_FUNCTION__); \
qDebug() << QTime::currentTime();

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *result) override{
        if (strcmp(eventType.data(), "xcb_generic_event_t")){
            __P__
            return false;
        } else {
            __P__
            printf("eventType: %s\n", eventType.data());
            printf("message->response_type: %u\n", ((xcb_generic_event_t*)message)->response_type);
            printf("result: %ld\n", *result);
//            return true;
            // Here should be true in common.
            return false;
        }
    }

    virtual bool eventFilter(QObject *watched, QEvent *event) override {
        __P__
        printf("event->type(): %d\n", event->type());
//        return true;
        // Here should be true in common.
        return false;
    }

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
