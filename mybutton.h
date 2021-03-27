#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QEvent>
#include <QTime>

#define __P__ qDebug() << "----------------------"; \
qDebug(__PRETTY_FUNCTION__); \
qDebug() << QTime::currentTime();

class MyButton : public QPushButton
{
public:
    MyButton(QPushButton*);
protected:
    virtual bool event(QEvent *e) override {
        __P__
        qDebug() << e->type();
        return QPushButton::event(e);
    }

    virtual void focusInEvent(QFocusEvent *e) override {
        __P__
        this->setStyleSheet("background:red");
        return; //eat the event!
    }

    virtual void focusOutEvent(QFocusEvent *e) override {
        __P__
        this->setStyleSheet("background:pink");
        return; //eat the event!
    }

    virtual bool eventFilter(QObject *watched, QEvent *event) override {
        switch (event->type()) {
        case QEvent::HoverEnter:
            this->setStyleSheet("background:black");
            return true;
        case QEvent::HoverLeave:
            this->setStyleSheet("background:yellow");
            return true;
        case QEvent::FocusIn:
            this->setStyleSheet("background:purple");
            return true;
        case QEvent::FocusOut:
            this->setStyleSheet("background:blue");
            return true;
        default:
            return QPushButton::eventFilter(watched, event);
        }
    }
};

#endif // MYBUTTON_H
