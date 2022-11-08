#include "playscene.h"
#include<QPushButton>
#include"data.h"
#include<QPainter>
#include<QDebug>
#include<QMessageBox>
#include"mypushbutton.h"
#include"mylabel.h"
#include<QTimer>
#include<QCursor>
#include"defensetower1.h"
#include"defensetower2.h"
#include<QMouseEvent>
#include"enemy1.h"
#include"enemy2.h"
#include<QTime>
#include"plant2.h"
playscene::playscene(int i)
{
    stage=i;
    qDebug()<<QString::number(stage);
    gamedata da(this);
    for(int j=0;j<=4;j++)
    {
        for(int p=0;p<=8;p++)
        {
            this->b[j][p]=da.a[i][j][p];
        }
    }
    signal=0;
    counter=0;
    QTimer *timer=new QTimer(this);
    timer->start(100);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(timer,&QTimer::timeout,[=](){
        if(counter>300&&enemyVec.empty())
        {
            timer->stop();
            QLabel *l1=new QLabel(this);
            QPixmap pix(":/game/006.png");
            pix=pix.scaled(QSize(pix.width()*0.5,pix.height()*0.5));
            l1->setPixmap(pix);
            l1->setFixedSize(pix.width(),pix.height());
            l1->move(300,100);
            l1->show();
        }

        int hangshu=qrand()%5;
        //qDebug()<<hangshu;
        if(b[hangshu][0]==1&&counter%5==0&&counter<=300)
        {
            enemy1 *e1=new enemy1;
            e1->CoorX=1001;
            e1->CoorY=10+hangshu*100;
            e1->route=hangshu;
            enemyVec.push_back(e1);
        }
        update();
        counter++;        
        for(auto ene=enemyVec.begin();ene!=enemyVec.end();)
        {
            if((*ene)->CoorX<=140)
            {
                timer->stop();
                QLabel *l1=new QLabel(this);
                QPixmap pix(":/game/001.png");
                pix=pix.scaled(QSize(pix.width()*0.5,pix.height()*0.5));
                l1->setPixmap(pix);
                l1->setFixedSize(pix.width(),pix.height());
                l1->move(300,100);
                l1->show();
            }
            (*ene)->Attack(plantVec);
            if((*ene)->move==1)
            {
            (*ene)->CoorX-=(*ene)->speed;
            }
            (*ene)->value++;
            ene++;
        }
            for(auto pla=plantVec.begin();pla!=plantVec.end();)
            {
                if((*pla)->health<=0)
                {
                    b[((*pla)->CoorY-70)/100][((*pla)->CoorX-254)/83]=1;
                    for(auto ene=enemyVec.begin();ene!=enemyVec.end();ene++)
                    {
                        if((*ene)->targetplant==(*pla))
                        {(*ene)->move=1;
                         (*ene)->targetplant=NULL;}
                    }
                    delete *pla;
                    pla=plantVec.erase(pla);
                    continue;
                }
                pla++;
            }
        for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
        {
            (*tow)->Attack(enemyVec);
            (*tow)->counter++;
        }
    });

    this->setFixedSize(1011,600);
    this->setWindowTitle(QString("第%1关").arg(i+1));
    QPushButton *btn2=new QPushButton(this);
    QPixmap pix(":/game/008.png");
    pix=pix.scaled(QSize(pix.width()*0.05,pix.height()*0.05));
    btn2->setIcon(pix);
    btn2->setFixedSize(pix.width()-50,pix.height()-50);
    btn2->move(this->width()-pix.width()+52,this->height()-pix.height()+52);
    connect(btn2,&QPushButton::clicked,[=](){
        //if(QMessageBox::Yes==(QMessageBox::question(this,"ques","数据将不会被保存，确认退出吗",QMessageBox::Yes|QMessageBox::No)))
        emit back();
    });
    QPushButton *btn3=new QPushButton("tower1",this);
    //btn3->setParent(this);
    btn3->resize(80,30);
    btn3->move(50,50);
    connect(btn3,&QPushButton::clicked,[=](){signal=1;});
    QPushButton *btn4=new QPushButton("tower2",this);
    btn4->resize(80,30);
    btn4->move(50,100);
    connect(btn4,&QPushButton::clicked,[=](){signal=2;});
    QPushButton *btn5=new QPushButton("nuts",this);
    btn5->resize(80,30);
    btn5->move(50,150);
    connect(btn5,&QPushButton::clicked,[=](){signal=3;});
    QPushButton *btn6=new QPushButton("snowPea",this);
    btn6->resize(80,30);
    btn6->move(50,200);
    connect(btn6,&QPushButton::clicked,[=](){signal=4;});
}
void playscene::mousePressEvent(QMouseEvent *ev)
{
    if(signal==0)
    {
        return;}
    else
    {
        if((ev->x()-254)/83>=0&&((ev->y()-70)/100)>=0&&((ev->x()-254)/83<10)&&((ev->y()-70)/100)<6)
       {          
       {switch(signal)
       {case 1:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]!=0)
                            return;
                    else
       {b[(ev->y()-70)/100][(ev->x()-254)/83]=100;
       defensetower1 *tower1=new defensetower1;
       tower1->CoorX=((ev->x()-254)/83)*83+254;
       tower1->CoorY=((ev->y()-70)/100)*100+70;
       towerVec.push_back(tower1);break;}
       case 2:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]!=0)
                        return;
                    else
                {b[(ev->y()-70)/100][(ev->x()-254)/83]=100;
                defensetower2 *tower2=new defensetower2;
                tower2->CoorX=((ev->x()-254)/83)*83+254;
                tower2->CoorY=((ev->y()-70)/100)*100+70;
                towerVec.push_back(tower2);break;}
        case 3:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==1)
                    {
                        b[(ev->y()-70)/100][(ev->x()-254)/83]=2;
                        plant1 *nut=new plant1;
                        nut->route=(ev->y()-70)/100;
                        nut->CoorX=((ev->x()-254)/83)*83+254;
                        nut->CoorY=((ev->y()-70)/100)*100+70;
                        plantVec.push_back(nut);break;
                    }
        case 4:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==1)
                    {
                        b[(ev->y()-70)/100][(ev->x()-254)/83]=3;
                        plant2 *snowPea=new plant2;
                        snowPea->route=(ev->y()-70)/100;
                        snowPea->CoorX=((ev->x()-254)/83)*83+254;
                        snowPea->CoorY=((ev->y()-70)/100)*100+70;
                        plantVec.push_back(snowPea);break;
                    }

                }
       signal=0;
       //qDebug()<<"rtyuj";
            }
        }

    }
}
void playscene::drawEnemy(QPainter &painter)
{
    for(auto ene=enemyVec.begin();ene!=enemyVec.end();)
    {
        QPixmap pix;
        if((*ene)->health>0)
            pix.load(QString((*ene)->PicturePath).arg((*ene)->value%22));
        else
        {pix.load(":/game/BoomDie_0.png");
        (*ene)->value=-100;
            for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
            {
                if((*tow)->targetEnemy==(*ene))
                {
                    (*tow)->targetEnemy=NULL;
                }
            }
        }
        painter.drawPixmap((*ene)->CoorX,(*ene)->CoorY,pix);
        ene++;
    }
}

void playscene::drawMap(QPainter &painter)
{
        //myLabel *btn=new myLabel[45];
        QPixmap pix5;
        for(int j=0;j<=4;j++)
        {
                for(int p=0;p<=8;p++)
                {
                    if(b[j][p]!=0&&b[j][p]!=100)
                    {
                        pix5.load(":/game/005.png");
                         //continue;
                    }
                    else
                    {
                        pix5.load(":/game/004.png");
                        //btn[j*9+p].setPixmap(pix5);
                        //qDebug()<<stage;
                    }
                    painter.drawPixmap(p*83+254,j*100+70,pix5);
                    //painter.drawPixmap()
                    //btn[j*9+p].setFixedSize(pix5.width(),pix5.height());
                    //btn[j*9+p].setStyleSheet("QPushButton(border:0px;)");
                    //btn[j*9+p].setIconSize(QSize(pix5.width(),pix5.height()));
                    //btn[j*9+p].setParent(this);
                    //btn[j*9+p].move(p*83+250,j*100+70);
                }
        }
}
void playscene::drawPlant(QPainter &painter)
{
    for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
    {
        QPixmap pix;
        if((*pla)->range==0)//坚果
        pix.load((*pla)->PicturePath);
        else//豌豆
        {
            pix.load(QString((*pla)->PicturePath).arg((*pla)->value%15));
            (*pla)->value++;
        }
        painter.drawPixmap((*pla)->CoorX,(*pla)->CoorY,pix);
    }
}

void playscene::drawTower(QPainter &painter)
{
    for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
    {
        QPixmap pix;
        pix.load((*tow)->PicturePath);
        //QPainter painter(this);
        painter.translate((*tow)->CoorX+41.5,(*tow)->CoorY+50);
        painter.rotate((*tow)->angle);
        painter.translate(-(*tow)->CoorX-41.5,-(*tow)->CoorY-50);
        painter.drawPixmap((*tow)->CoorX,(*tow)->CoorY,pix);
        painter.resetTransform();
    }
}
void playscene::drawBullet(QPainter &painter)
{
    for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
    {
        for(auto bull=(*tow)->bulletVec.begin();bull!=(*tow)->bulletVec.end();bull++)
        {
            QPixmap pix;
            if((*bull)->signal==4)
            {pix.load(":/game/014.png");}
            if((*bull)->signal==5)
            {pix.load(":/game/015.png");
            //qDebug()<<"duile";
            (*bull)->signal=0;}
            painter.drawPixmap((*bull)->CoorX,(*bull)->CoorY,pix);
        }
    }
    for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
    {
        for(auto bul=(*pla)->bulletVec.begin();bul!=(*pla)->bulletVec.end();bul++)
        {
            QPixmap pix(":/game/Pealce_0.png");
            painter.drawPixmap((*bul)->CoorX,(*bul)->CoorY,pix);
        }
    }
}

void playscene::paintEvent(QPaintEvent *)
{
    QPixmap pix;
    QPainter painter(this);
    pix.load(":/game/009.png");
    painter.drawPixmap(0,0,pix);
    drawMap(painter);
    drawTower(painter);
    drawEnemy(painter);
    drawBullet(painter);
    drawPlant(painter);

}
