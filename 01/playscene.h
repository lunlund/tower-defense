#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"mypushbutton.h"
#include"mylabel.h"
#include"towerbase.h"
#include<QPainter>
class playscene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit playscene(QWidget *parent = 0);
    int counter;
    playscene(int i);
    int stage;
    void paintEvent(QPaintEvent *);
    int b[5][9];
    int signal;
    QVector<towerbase*> towerVec;
    QVector<enemybase*> enemyVec;
    void mousePressEvent(QMouseEvent *ev);
    void drawTower(QPainter &painter);
    void drawMap(QPainter &painter);
    void drawEnemy(QPainter &pianter);
    void drawBullet(QPainter &painter);
signals:void back();

public slots:

};

#endif // PLAYSCENE_H
