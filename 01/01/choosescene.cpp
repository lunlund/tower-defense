#include "choosescene.h"
#include<QPainter>
#include<QLabel>
#include"mypushbutton.h"
#include<QDebug>
choosescene::choosescene(QWidget *parent) :
    QMainWindow(parent)
{
    //play=new playscene;
    setFixedSize(926,518);
    setWindowTitle("选择界面");
    //QPixmap pix(":/game/007.png");
    QPushButton *btn2=new QPushButton(this);
    QPixmap pix(":/game/008.png");
    pix=pix.scaled(QSize(pix.width()*0.05,pix.height()*0.05));
    btn2->setIcon(pix);
    btn2->setFixedSize(pix.width()-50,pix.height()-50);
    btn2->move(926-pix.width()+52,518-pix.height()+52);
    connect(btn2,&QPushButton::clicked,[=](){
        emit back();
    });
    for(int i=0;i<=2;i++)
    {
        myPushButton *btn=new myPushButton(":/game/007.png");
        btn->setParent(this);
        btn->move(i*300+100,250);
        QLabel *label=new QLabel(this);
        label->setFixedSize(btn->width(),btn->height());
        QFont font;
        font.setBold(1);
        font.setPointSize(150);
        QString str=QString::number(i+1);
        label->setText(str);
        label->move(i*300+100,250);
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
        label->setAlignment(Qt::AlignCenter);
        label->setFont(font);
        connect(btn,&myPushButton::clicked,[=](){
            qDebug()<<QString("第%1关").arg(i+1);
            play=new playscene(i);
            this->hide();
            play->show();
            connect(play,&playscene::back,[=]()
            {
                play->hide();
                delete play;
                this->show();
            });
        });

    }


}
void choosescene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/game/003.png");
    //qDebug()<<pix.width()<<pix.height();
    painter.drawPixmap(0,0,pix);
}
