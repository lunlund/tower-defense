#include "plant2.h"

plant2::plant2(QObject *parent) :
    Plants(parent)
{
    //value=0;
    CoorX=0;
    CoorY=0;
    range=200;//横向射程
    attackpower=200;
    //enemybase* targetEnemy=NULL;
    PicturePath=":/game/SnowPea_%1.png";
    //void Attack(QVector<enemybase*> &enemy);
    //counter=0;//counter/5才攻击一次
    health=1000;
    interval=3;
}
//void plant2::Attack(QVector<enemybase*> &enemy)
//{
//    for(auto ene=enemy.begin();ene!=enemy.end();ene++)
//    {
//        if((*ene)->route==route&&(*ene)->CoorX-CoorX<=range&&(*ene)->CoorX-CoorX>=0)
//        {

//        }
//    }

//}
