#include "enemybase.h"
#include<QDebug>

enemybase::enemybase(QObject *parent) :
    QObject(parent)
{
    move=1;
}
void enemybase::Attack(QVector<Plants*> &plants)
{
        if(targetplant==NULL||targetplant->health<=0)
            move=1;
    for(auto pla=plants.begin();pla!=plants.end();)
    {
        if((*pla)->route==route)
        {
            if(CoorX+100-((*pla)->CoorX+65)<=10&&CoorX+100-((*pla)->CoorX+65)>=0)
            {
                targetplant=(*pla);
                move=0;
                (*pla)->health-=this->attack;
            }
        }
        pla++;
    }
//    for(auto pla=plants.begin();pla!=plants.end();)
//    {
//        if((*pla)->health<=0)
//        {
//            if((*pla)==targetplant)
//            {targetplant=NULL;
//                move=1;
//                //qDebug()<<"iugbogb";
//            }
//            delete *pla;
//            pla=plants.erase(pla);
//            continue;
//        }
//        pla++;
//    }

}

