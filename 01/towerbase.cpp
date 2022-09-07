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
//    double dis;
//    int x,y;
//A:
//    //targetEnemy=enemy[0];
//    if(targetEnemy==NULL)
//    {enemybase *enemyIt=enemy.front();
//    for(int i=0;i<=enemy.size()-1;i++)
//    {
//        if(i==0)
//        {
//            dis=distance(enemy[i]->CoorX,enemy[i]->CoorY,this->CoorX,this->CoorY);
//        }
//        else
//        {
//            if(distance(enemy[i]->CoorX,enemy[i]->CoorY,this->CoorX,this->CoorY)<dis)
//            {
//                dis=distance(enemy[i]->CoorX,enemy[i]->CoorY,this->CoorX,this->CoorY);
//                enemyIt=enemy[i];
//            }
//        }
//    }
//    if(dis<=range)
//    {
//        this->targetEnemy=enemyIt;
//    }
//    else
//    {targetEnemy=NULL;}
//    }

//    else
//    {
//        if(distance(targetEnemy->CoorX,targetEnemy->CoorY,CoorX,CoorY)>range)
//        {targetEnemy=NULL;
//            goto A;}
//        angle=qAtan2((targetEnemy->CoorY-this->CoorY),(targetEnemy->CoorX-this->CoorX))*180/3.1415;
//        if(targetEnemy->CoorY-this->CoorY<0&&targetEnemy->CoorX-this->CoorX<0)
//        {
//            angle=angle+180;
//        }
//        if(targetEnemy->CoorY-this->CoorY<0&&targetEnemy->CoorX-this->CoorX>0)
//        {
//            angle=angle+180;
//        }
//        angle=-angle;
//        bullet *bull=new bullet;
//        bull->x=30*cos(-angle);
//        bull->y=30*sin(-angle);
//        bull->CoorX=this->CoorX+41.5;
//        bull->CoorY=this->CoorY+50;
//        bulletVec.push_back(bull);
//    }
//    for(int i=0;i<=this->bulletVec.size()-1;i++)
//    {
//        bulletVec[i]->CoorX+=x;
//        bulletVec[i]->CoorY+=y;
//        if(distance(bulletVec[i]->CoorX,bulletVec[i]->CoorY,targetEnemy->CoorX,targetEnemy->CoorY)<20)
//        {targetEnemy->health-=this->attackpower;
//            bulletVec.erase(bulletVec.begin()+i);
//                        delete bulletVec[i];}
//        if(bulletVec[i]->CoorX<0||bulletVec[i]->CoorY<0||bulletVec[i]->CoorY>600||bulletVec[i]->CoorX>1011)
//           { bulletVec.erase(bulletVec.begin()+i);
//            delete bulletVec[i];}

//    }
//    for(int i=0;i<=enemy.size()-1;i++)
//    {
//        if(enemy[i]->health<=0)
//        {
//            enemy.erase(enemy.begin()+i);
//            delete enemy[i];
//        }

//    }
    if(counter%5==0)
           { targetEnemy=enemy[0];
            angle=-qAtan2((this->CoorY-targetEnemy->CoorY),(targetEnemy->CoorX-this->CoorX))*180/3.1415;
            bullet *bull=new bullet;
            bull->x=100*qCos(-angle*3.1415/180);
            bull->y=100*qSin(-angle*3.1415/180);
            bull->CoorX=this->CoorX+41.5*qCos(-angle*3.1415/180);
            bull->CoorY=this->CoorY+50*qSin(-angle*3.1415/180);
            bull->signal=4;
            bull->time=0;
            bulletVec.push_back(bull);
            for(auto bul=bulletVec.begin();bul!=bulletVec.end();)
            {
                if((*bul)->signal==0)
                {delete *bul;
                 bul=bulletVec.erase(bul);
                 continue;
                }
                (*bul)->CoorX+=bull->x;
                (*bul)->CoorY-=bull->y;
                if(distance((*bul)->CoorX,(*bul)->CoorY,targetEnemy->CoorX,targetEnemy->CoorY)<=100)
                {(*bul)->signal=5;
                    targetEnemy->health-=attackpower;
                    (*bul)->time++;
                }
                bul++;
           }
//            QVector<bullet*> ::iterator bullIt;
//            bullIt=bulletVec.begin();

//            while(bullIt!=bulletVec.end())
//            {

//                if((*bullIt)->signal==5&&(*bullIt)->time==2)
//                {
//                    bullIt=bulletVec.erase(bullIt);
//                    delete *bullIt;
//                    break;

//                }
//                else
//                {bullIt++;}

//            }
    }
//            for(auto bullIt=bulletVec.begin();bullIt!=bulletVec.end();bullIt++)
//            {
//                if(*bullIt->signal==5&&*bullIt->time==2)
//                {
//                   //bullet *bull_=bulletVec[i];
//                    bulletVec.erase(bullIt);
//                    delete *bullIt;}
//            }

    //if enemy over the range or the target dies, the target will be null
    //if over the range or beat the enemy, the bull will be pop
    //the blood of enemy will decrease if beaten

}
