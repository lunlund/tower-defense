#include "mylabel.h"

myLabel::myLabel()
{
    //this->pix=pix;
    //this->setStyleSheet("QLabel{backgroung-color:transparent;}");
}
void myLabel::enterEvent(QEvent *)
{
//    QPixmap pix2(":/game/004.png");//grey
//    if(pix==pix2)
//    {
//        QCursor cursor(Qt::ArrowCursor);
//        setCursor(cursor);
//    }
}

void myLabel::leaveEvent(QEvent *)
{

}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
     emit clicked();
}
void myLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
}
