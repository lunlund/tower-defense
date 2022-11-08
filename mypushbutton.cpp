#include "mypushbutton.h"

//myPushButton::myPushButton(QWidget *parent) :
//    QMyPushButton(parent)
//{
//}
myPushButton::myPushButton(QString string)
{
    this->string=string;
    QPixmap pix;
    pix.load(string);
    this->pix=pix;
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton(border:0px;)");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
myPushButton::myPushButton(QPixmap pix)
{
    this->string="1";
    this->pix=pix;
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton(border:0px;)");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
