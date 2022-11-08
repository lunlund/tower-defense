#include "plant1.h"

plant1::plant1(QObject *parent) :
    Plants(parent)
{
    CoorX=0;
    CoorY=0;
    range=0;
    //attackpower=200;
    //enemybase* targetEnemy=NULL;
    PicturePath=":/game/016.png";
    //void Attack(QVector<enemybase*> &enemy);
    //counter=0;//counter/5才攻击一次
    health=3000;
    interval=3;
}
