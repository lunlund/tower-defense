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
#include<algorithm>
playscene::playscene(int i)
{
    stage=i;
    qDebug()<<QString::number(stage);
    gamedata da(this);
    int valid=0;
    int cc[5]={0,0,0,0,0};
    for(int j=0;j<=4;j++)
    {
        for(int p=0;p<=8;p++)
        {
            this->b[j][p]=da.a[i][j][p];
        }
        if(b[j][0]==1)
        {
            cc[valid]=j;
            valid++;
        }
    }
    signal=0;
    counter=0;
    QTimer *timer=new QTimer(this);
    timer->start(100);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    connect(timer,&QTimer::timeout,[=](){
        if(counter>1000&&enemyVec.empty())
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

        int hangshu=cc[qrand()%valid];
        //qDebug()<<hangshu;
        if(counter%5==0&&counter<=1000)//if(b[hangshu][0]==1&&counter%5==0&&counter<=300)
        {

            enemy1 *e1=new enemy1;
            e1->kind=qrand()%4;
            if(e1->kind==2||e1->kind==3)
                e1->speed=7;
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
            for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)//针对豌豆射手
            {
                if((*pla)->attackpower!=0)
                {
                    (*pla)->Attack(enemyVec);
                    (*pla)->counter++;
                }
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
    QPushButton *btn7=new QPushButton("狂暴",this);
    btn7->resize(80,30);
    btn7->move(50,250);
    connect(btn7,&QPushButton::clicked,[=](){
        if(texiao[0]>0)
        {   signal=5;
            texiao[0]--;
        }
    });
    QPushButton *btn8=new QPushButton("冰系",this);
    btn8->resize(80,30);
    btn8->move(50,300);
    connect(btn8,&QPushButton::clicked,[=](){
        if(texiao[1]>0)
           { signal=6;
        texiao[1]--;
        }
    });
    QPushButton *btn9=new QPushButton("群伤",this);
    btn9->resize(80,30);
    btn9->move(50,350);
    connect(btn9,&QPushButton::clicked,[=](){
        if(texiao[2]>0)
           { signal=7;
            texiao[2]--;
        }
    });
    QPushButton *btn10=new QPushButton("放血",this);
    btn10->resize(80,30);
    btn10->move(50,400);
    connect(btn10,&QPushButton::clicked,[=](){
        if(texiao[3]>0)
        {signal=8;
            texiao[3]--;
        }});
    QPushButton *btn11=new QPushButton("删狂暴",this);
    btn11->resize(60,30);
    btn11->move(140,250);
    connect(btn11,&QPushButton::clicked,[=](){signal=11;});
    QPushButton *btn12=new QPushButton("删冰系",this);
    btn12->resize(60,30);
    btn12->move(140,300);
    connect(btn12,&QPushButton::clicked,[=](){signal=12;});
    QPushButton *btn13=new QPushButton("删群伤",this);
    btn13->resize(60,30);
    btn13->move(140,350);
    connect(btn13,&QPushButton::clicked,[=](){signal=13;});
    QPushButton *btn14=new QPushButton("删放血",this);
    btn14->resize(60,30);
    btn14->move(140,400);
    connect(btn14,&QPushButton::clicked,[=](){signal=14;});
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
       towerVec.push_back(tower1);break;}break;
       case 2:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]!=0)
                        return;
                    else
                {b[(ev->y()-70)/100][(ev->x()-254)/83]=101;
                defensetower2 *tower2=new defensetower2;
                tower2->CoorX=((ev->x()-254)/83)*83+254;
                tower2->CoorY=((ev->y()-70)/100)*100+70;
                towerVec.push_back(tower2);break;}break;
        case 3:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==1)
                    {
                        b[(ev->y()-70)/100][(ev->x()-254)/83]=2;
                        plant1 *nut=new plant1;
                        nut->route=(ev->y()-70)/100;
                        nut->CoorX=((ev->x()-254)/83)*83+254;
                        nut->CoorY=((ev->y()-70)/100)*100+70;
                        plantVec.push_back(nut);break;
                    }break;
        case 4:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==1)
                    {
                        b[(ev->y()-70)/100][(ev->x()-254)/83]=3;
                        plant2 *snowPea=new plant2;
                        snowPea->route=(ev->y()-70)/100;
                        snowPea->CoorX=((ev->x()-254)/83)*83+254;
                        snowPea->CoorY=((ev->y()-70)/100)*100+70;
                        plantVec.push_back(snowPea);break;
                    }break;
        case 5:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==3)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=8;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=8;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==9)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=14;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=14;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==10)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=15;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=15;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }break;
       case 6:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==3)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=9;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=9;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==8)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=14;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=14;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==10)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=16;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=16;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }break;
       case 7:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==3)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=10;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=10;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==8)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=15;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=15;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==9)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind=16;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]=16;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }break;
        case 8:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==100||b[(ev->y()-70)/100][(ev->x()-254)/83]==101)
                    {
                        for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
                        {
                            if((*tow)->CoorX==((ev->x()-254)/83)*83+254&&(*tow)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*tow)->kind+=8;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]+=8;
                                //qDebug()<<"bic";
                                break;
                            }
                        }
                    }break;
       case 11:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==8||b[(ev->y()-70)/100][(ev->x()-254)/83]==14||b[(ev->y()-70)/100][(ev->x()-254)/83]==15)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind-=5;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]-=5;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }break;
       case 12:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==9||b[(ev->y()-70)/100][(ev->x()-254)/83]==14||b[(ev->y()-70)/100][(ev->x()-254)/83]==16)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind-=6;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]-=6;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }break;
       case 13:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]==10||b[(ev->y()-70)/100][(ev->x()-254)/83]==15||b[(ev->y()-70)/100][(ev->x()-254)/83]==16)
                    {
                        for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
                        {
                            if((*pla)->CoorX==((ev->x()-254)/83)*83+254&&(*pla)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*pla)->kind-=7;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]-=7;
                                //qDebug()<<"bi";
                                break;
                            }
                        }
                    }break;
       case 14:
                    if(b[(ev->y()-70)/100][(ev->x()-254)/83]>106)
                    {
                        for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
                        {
                            if((*tow)->CoorX==((ev->x()-254)/83)*83+254&&(*tow)->CoorY==((ev->y()-70)/100)*100+70)
                            {
                                (*tow)->kind-=8;
                                b[(ev->y()-70)/100][(ev->x()-254)/83]-=8;
                                //qDebug()<<"bic";
                                break;
                            }
                        }
                    }break;

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
            texiao[((*ene)->value+(*ene)->CoorX+(*ene)->kind)%4]++;
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
                    if(b[j][p]!=0&&b[j][p]<100)
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
//        for(int i=0;i<=3;i++)//250,300,350,400,+100
//        {
//            QFont font;
//            font.setPixelSize(30);
//            painter.setFont(font);
//            painter.setPen(Qt::blue);
//            painter.drawText(50,340+i*50,QString::number(texiao[i]));
//        }
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
            QPixmap pix(":/game/PeaIce_0.png");
            painter.drawPixmap((*bul)->CoorX,(*bul)->CoorY,pix);
            if((*bul)->signal==5)
                (*bul)->signal=0;
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
    for(int i=0;i<=3;i++)//250,300,350,400,+100
    {
        QFont font;
        font.setPixelSize(30);
        painter.setFont(font);
        painter.setPen(Qt::blue);
        painter.drawText(10,280+i*50,QString::number(texiao[i]));
    }
    for(auto ene=enemyVec.begin();ene!=enemyVec.end();ene++)
    {
        QFont font;
        font.setPixelSize(20);
        painter.setFont(font);
        painter.setPen(Qt::blue);
        if((*ene)->kind==0)
        painter.drawText((*ene)->CoorX+60,(*ene)->CoorY+20,QString("普通(%1)").arg(QString::number((*ene)->health)));
        if((*ene)->kind==1)
        painter.drawText((*ene)->CoorX+60,(*ene)->CoorY+20,QString("闪现(%1)").arg(QString::number((*ene)->health)));
        if((*ene)->kind==2)
        painter.drawText((*ene)->CoorX+60,(*ene)->CoorY+20,QString("神速(%1)").arg(QString::number((*ene)->health)));
        if((*ene)->kind==3)
        painter.drawText((*ene)->CoorX+60,(*ene)->CoorY+20,QString("闪+神(%1)").arg(QString::number((*ene)->health)));
    }
    for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
    {
        QFont font;
        font.setPixelSize(20);
        painter.setFont(font);
        painter.setPen(Qt::color0);
        if((*pla)->kind==-1)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("坚果(%1)").arg(QString::number((*pla)->health)));
        }
        if((*pla)->kind==3)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("普通(%1)").arg(QString::number((*pla)->health)));
        }
        if((*pla)->kind==8)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("狂暴(%1)").arg(QString::number((*pla)->health)));
        }
        if((*pla)->kind==9)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("冰系(%1)").arg(QString::number((*pla)->health)));
        }
        if((*pla)->kind==10)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("群伤(%1)").arg(QString::number((*pla)->health)));
        }
        if((*pla)->kind==14)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("狂+冰(%1)").arg(QString::number((*pla)->health)));
        }
        if((*pla)->kind==15)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("狂+群(%1)").arg(QString::number((*pla)->health)));
        }
        if((*pla)->kind==16)
        {
            painter.drawText((*pla)->CoorX,(*pla)->CoorY,QString("冰+群(%1)").arg(QString::number((*pla)->health)));
        }
    }
    for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
    {
        QFont font;
        font.setPixelSize(20);
        painter.setFont(font);
        painter.setPen(Qt::color1);
        if((*tow)->kind<106)
        {
            painter.drawText((*tow)->CoorX,(*tow)->CoorY,"普通");
        }
        else
        {
            painter.drawText((*tow)->CoorX,(*tow)->CoorY,"放血");
        }
    }
    QFont font;
    font.setPixelSize(50);
    font.setOverline(1);
    font.setBold(1);
    font.setItalic(1);
    painter.setFont(font);
    painter.setPen(Qt::black);
    if(counter>1000)
        painter.drawText(50,40,QString::number(0));
    else
        painter.drawText(50,40,QString::number((1000-counter)/10));

}
playscene::~playscene()
{
    for(auto pla=plantVec.begin();pla!=plantVec.end();pla++)
    {
        for(auto bul=(*pla)->bulletVec.begin();bul!=(*pla)->bulletVec.end();bul++)
        {
            delete *bul;
        }
        (*pla)->bulletVec.clear();
        delete *pla;
    }
    plantVec.clear();
    for(auto tow=towerVec.begin();tow!=towerVec.end();tow++)
    {
        for(auto bul=(*tow)->bulletVec.begin();bul!=(*tow)->bulletVec.end();bul++)
        {
            delete *bul;
        }
        (*tow)->bulletVec.clear();
        delete *tow;
    }
    towerVec.clear();
    for(auto ene=enemyVec.begin();ene!=enemyVec.end();ene++)
    {
        delete *ene;
    }
    enemyVec.clear();
}
