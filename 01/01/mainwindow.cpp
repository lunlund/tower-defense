#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QDebug>
#include"mypushbutton.h"
#include"choosescene.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    choose=new choosescene(this);
    setFixedSize(926,518);
    setWindowTitle("植物大战僵尸");
    myPushButton *btn=new myPushButton(":/game/002.png");
    btn->setParent(this);
    btn->move(this->width()*0.5-btn->width()*0.5,400);
    connect(btn,&myPushButton::clicked,[=](){
        this->hide();
        choose->show();
    });
    connect(choose,&choosescene::back,[=](){
        this->show();
        choose->hide();
    });
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/game/003.png");
    //qDebug()<<pix.width()<<pix.height();
    painter.drawPixmap(0,0,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}
