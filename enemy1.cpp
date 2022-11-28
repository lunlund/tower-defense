#include "enemy1.h"

enemy1::enemy1(QObject *parent) :
    enemybase(parent)
{
    speed=3;
    value=0;
    PicturePath=":/game/Zombie_%1.png";
    CoorX=0;
    CoorY=0;
    health=1000;
    attack=200;
    move=1;
    kind=0;

}
//void enemy1::Attack(QVector<Plants *> &plants)
//{
//    for(auto pla=plants.begin();pla!=plants.end();)
//    {
//        if((*pla)->health<=0)
//        {
//            delete *pla;
//            pla=plants.erase(pla);
//            continue;
//        }
//        if((*pla)->route==route)
//        {
//            if(CoorX+100-((*pla)->CoorX+65)<=10)
//            {
//                targetplant=(*pla);
//                move=0;
//                (*pla)->health-=this->attack;
//            }
//        }
//        pla++;
//    }
//    if(targetplant==NULL)
//        move=1;
//}

