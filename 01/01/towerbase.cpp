#include "towerbase.h"
#include<QtCore/qmath.h>
#include<QDebug>
towerbase::towerbase(QObject *parent) :
    QObject(parent)
{

}
double towerbase::distance(int a,int b,int c,int d)
{
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
void towerbase::Attack(QVector<enemybase*> &enemy)
{
            if(counter%10==0&&targetEnemy!=NULL)
           {angle=-qAtan2((this->CoorY+50-targetEnemy->CoorY-70),(targetEnemy->CoorX+100-this->CoorX-41.5))*180/3.1415;
                bullet *bull=new bullet;
                bull->x=50*qCos(-angle*3.1415/180);
                bull->y=50*qSin(-angle*3.1415/180);
                bull->CoorX=this->CoorX+41.5*qCos(-angle*3.1415/180);
                bull->CoorY=this->CoorY+50*qSin(-angle*3.1415/180);
                bull->signal=4;
                bull->time=0;
                bull->targetenemy=targetEnemy;
                bulletVec.push_back(bull);}
                if(enemy.size()==0)
                {
                    for(auto bul=bulletVec.begin();bul!=bulletVec.end();bul++)
                    {
                        delete *bul;
                    }
                    bulletVec.clear();
                    return;
                }

            // if(targetEnemy!=NULL)
           // {targetEnemy=enemy[0];
//            angle=-qAtan2((this->CoorY-targetEnemy->CoorY),(targetEnemy->CoorX-this->CoorX))*180/3.1415;
//            bullet *bull=new bullet;
//            bull->x=100*qCos(-angle*3.1415/180);
//            bull->y=100*qSin(-angle*3.1415/180);
//            bull->CoorX=this->CoorX+41.5*qCos(-angle*3.1415/180);
//            bull->CoorY=this->CoorY+50*qSin(-angle*3.1415/180);
//            bull->signal=4;
//            bull->time=0;
//            bulletVec.push_back(bull);
            for(auto bul=bulletVec.begin();bul!=bulletVec.end();)
            {
                if((*bul)->signal==0)
                {delete *bul;
                 bul=bulletVec.erase(bul);
                 continue;
                }
//                double angle1=-qAtan2(((*bul)->CoorY-(*bul)->targetenemy->CoorY),((*bul)->targetenemy->CoorX-(*bul)->CoorX))*180/3.1415;
//                            (*bul)->x=100*qCos(-angle1*3.1415/180);
//                            (*bul)->y=100*qSin(-angle1*3.1415/180);
                (*bul)->CoorX+=(*bul)->x;
                (*bul)->CoorY-=(*bul)->y;
                if(distance((*bul)->CoorX,(*bul)->CoorY,(*bul)->targetenemy->CoorX+100,(*bul)->targetenemy->CoorY+70)<=100)
                {(*bul)->signal=5;
                    (*bul)->targetenemy->health-=attackpower;
                    qDebug()<<(*bul)->targetenemy->health;
                    (*bul)->time++;
                }
                bul++;
           }
            for(auto ene=enemy.begin();ene!=enemy.end();)
            {
                if((*ene)->health<=0)
                {
                    if((*ene)==targetEnemy)
                        targetEnemy=NULL;
                    delete *ene;
                    ene=enemy.erase(ene);
                    continue;
                }
                if(targetEnemy!=NULL)
                {
                    if(distance(targetEnemy->CoorX+100,targetEnemy->CoorY+70,CoorX+41.5,CoorY+50)>range)
                        targetEnemy=NULL;
                }
                ene++;
            }

//                else
//                {
                    if(enemy.empty())
                        return;
                    double dis=distance(enemy[0]->CoorX+100,enemy[0]->CoorY+70,CoorX+41.5,CoorY+50);
                    if(dis<=range)
                    {
                        targetEnemy=enemy[0];
                    }
                    for(auto ene=enemy.begin();ene!=enemy.end();ene++)
                    {
                        if(distance((*ene)->CoorX+100,(*ene)->CoorY+70,CoorX+41.5,CoorY+50)<dis&&distance((*ene)->CoorX+100,(*ene)->CoorY+70,CoorX+41.5,CoorY+50)<=range)
                        {
                            dis=distance((*ene)->CoorX+100,(*ene)->CoorY+70,CoorX+41.5,CoorY+50);
                            targetEnemy=(*ene);

                        }
                    }
                    if(targetEnemy==NULL)
                        return;
                }
            //}
//            else
//            {
//            for(auto bul=bulletVec.begin();bul!=bulletVec.end();)
//            {
//                if((*bul)->signal==0||(*bul)->CoorX<0||(*bul)->CoorY<0)
//                {delete *bul;
//                 bul=bulletVec.erase(bul);
//                 continue;
//                }
//                (*bul)->CoorX+=(*bul)->x;
//                (*bul)->CoorY-=(*bul)->y;
//                if(targetEnemy!=NULL&&distance((*bul)->CoorX,(*bul)->CoorY,targetEnemy->CoorX,targetEnemy->CoorY)<=100)
//                {(*bul)->signal=5;
//                    targetEnemy->health-=attackpower;
//                    qDebug()<<targetEnemy->health;
//                    (*bul)->time++;
//                }
//                bul++;
//           }
//            for(auto ene=enemy.begin();ene!=enemy.end();)
//            {
//                if(targetEnemy!=NULL)
//                {
//                    if(distance(targetEnemy->CoorX,targetEnemy->CoorY,CoorX,CoorY)>range)
//                        targetEnemy=NULL;
//                }
//                ene++;
//            }
//            }


    //if enemy over the range or the target dies, the target will be null
    //if over the range or beat the enemy, the bull will be pop
    //the blood of enemy will decrease if beaten



