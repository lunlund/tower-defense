#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mypushbutton.h"
#include"mylabel.h"
#include"towerbase.h"
#include<QPainter>
#include"plants.h"
#include"plant1.h"
class playscene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit playscene(QWidget *parent = 0);
    int counter;
    playscene(int i);
    int stage;
    void paintEvent(QPaintEvent *);
    int b[5][9];//地皮为0未开发，可种远程炮，建完远程跑为100，建植物为2
    int signal;//信号1建塔1，信号2建塔2，信号3建坚果,4豌豆，5狂暴，6冰系，7群伤，8放血
    QVector<towerbase*> towerVec;
    QVector<enemybase*> enemyVec;
    void mousePressEvent(QMouseEvent *ev);
    void drawTower(QPainter &painter);
    void drawMap(QPainter &painter);
    void drawEnemy(QPainter &pianter);
    void drawBullet(QPainter &painter);
    void drawPlant(QPainter &painter);
    QVector<Plants*> plantVec;
    int texiao[4]={0,0,0,0};//狂暴冰系群伤放血
    ~playscene();
signals:void back();

public slots:

};

#endif // PLAYSCENE_H
