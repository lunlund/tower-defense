#include "bullet.h"

bullet::bullet(QObject *parent) :
    QObject(parent)
{
    CoorX=0;
    CoorY=0;
    x=0;
    y=0;
    targetenemy=NULL;
}
