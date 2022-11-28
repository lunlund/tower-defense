#include "defensetower2.h"
#include<QtCore/qmath.h>
defensetower2::defensetower2(QObject *parent) :
    towerbase(parent)
{
    PicturePath=":/game/018.png";
    CoorX=0;
    CoorY=0;
    angle=0;
    range=600;
    attackpower=100;
}
//void defensetower2::Attack(QVector<enemybase*> enemy)
//{
//    double dis;int x,y;A:
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
//    }}

//    else
//    {
//        if(distance(targetEnemy->CoorX,targetEnemy->CoorY,CoorX,CoorY))
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
//        x=30*cos(-angle);
//        y=30*sin(-angle);
//        bullet *bull=new bullet;
//        bull->CoorX=this->CoorX+41.5;
//        bull->CoorY=this->CoorY+50;
//        bulletVec.push_back(bull);
//    }
//    for(int i=0;i<=this->bulletVec.size()-1;i++)
//    {
//        bulletVec[i]->CoorX+=x;
//        bulletVec[i]->CoorY+=y;
//        if(distance(bulletVec[i]->CoorX,bulletVec[i]->CoorY,targetEnemy->CoorX,targetEnemy->CoorY))
//        {targetEnemy->health-=this->attackpower;
//            bulletVec.erase(bulletVec.begin()+i);
//                        delete bulletVec[i];}
//        if(bulletVec[i]->CoorX<0||bulletVec[i]->CoorY<0||bulletVec[i]->CoorY>600||bulletVec[i]->CoorX>1011)
//           { bulletVec.erase(bulletVec.begin()+i);
//            delete bulletVec[i];}

//    }//if enemy over the range or the target dies, the target will be null
//    //if over the range or beat the enemy, the bull will be pop
//    //the blood of enemy will decrease if beaten

//}
