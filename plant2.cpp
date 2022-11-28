#include "plant2.h"
#include<QDebug>

plant2::plant2(QObject *parent) :
    Plants(parent)
{
    //value=0;
    CoorX=0;
    CoorY=0;
    range=200;//横向射程
    attackpower=50;
    //enemybase* targetEnemy=NULL;
    PicturePath=":/game/SnowPea_%1.png";
    //void Attack(QVector<enemybase*> &enemy);
    //counter=0;//counter/5才攻击一次
    health=1000;
    interval=3;
}
void plant2::Attack(QVector<enemybase*> &enemy)
{
    if(counter%interval==0)
    {
    for(auto ene=enemy.begin();ene!=enemy.end();ene++)
    {
        if((*ene)->route==route&&(*ene)->CoorX-CoorX<=range&&(*ene)->CoorX-CoorX>=0)//25 100
        {
            bullet *bull=new bullet;
            bull->CoorX=this->CoorX+20;
            bull->CoorY=this->CoorY;
            bull->x=50;
            bull->y=0;
            //bull->targetenemy=(*ene);
            bulletVec.push_back(bull);
        }
    }
    }
    for(auto ene=enemy.begin();ene!=enemy.end();ene++)
    {
        for(auto bul=bulletVec.begin();bul!=bulletVec.end();)
        {
            if((*ene)->route==route&&(*ene)->CoorX+100-(*bul)->CoorX-25<=80&&(*ene)->CoorX+100-(*bul)->CoorX-25>=0)
            {
                (*ene)->health-=this->attackpower;
                qDebug()<<(*ene)->health;
                //(*bul)->signal=5;
                delete *bul;
                bul=bulletVec.erase(bul);
                continue;
            }
            bul++;
        }
    }
    for(auto ene=enemy.begin();ene!=enemy.end();)
    {
        if((*ene)->value<0)//if((*ene)->health<=0)
        {
            delete *ene;
            ene=enemy.erase(ene);
            continue;
            //(*ene)->value=-1000;
        }
        ene++;
    }
    for(auto bul=bulletVec.begin();bul!=bulletVec.end();)
    {
//        if((*bul)->signal==0)
//        {delete *bul;
//         bul=bulletVec.erase(bul);
//         continue;
//        }
        (*bul)->CoorX+=(*bul)->x;
        (*bul)->CoorY-=(*bul)->y;
        bul++;
   }

}
