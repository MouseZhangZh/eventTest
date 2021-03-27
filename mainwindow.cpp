#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyButton* mb = new MyButton(ui->pushButton);
    mb->setGeometry(1, 2, 33, 34);
    this->installEventFilter(mb);
}

MainWindow::~MainWindow()
{
    delete ui;
}

