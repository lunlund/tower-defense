#include "enemy1.h"
#include<QVector>
enemy1::enemy1(QObject *parent) :
    enemybase(parent)
{
    speed=7;
    value=0;
    PicturePath=":/game/Zombie_%1.png";
    CoorX=0;
    CoorY=0;
    health=1000;
    attack=30;

}

