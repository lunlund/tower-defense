#ifndef PLANTS_H
#define PLANTS_H

#include <QObject>
#include"enemybase.h"
#include"bullet.h"
#include<QVector>
class bullet;
class enemybase;
class Plants : public QObject
{
    Q_OBJECT
public:
    explicit Plants(QObject *parent = 0);
    int CoorX,CoorY;
    int range;//横向射程
    int attackpower;
    //enemybase* targetEnemy=NULL;
    QVector<bullet*> bulletVec;
    QString PicturePath;
    virtual void Attack(QVector<enemybase*> &enemy);
    double distance(int a,int b,int c,int d);
    int counter=0;
    int health;
    int interval;
    int route;
    int value;

signals:

public slots:

};

#endif // PLANTS_H
