#ifndef TOWERBASE_H
#define TOWERBASE_H

#include <QObject>
#include"enemybase.h"
#include"bullet.h"
#include<QVector>
class towerbase : public QObject
{
    Q_OBJECT
public:
    explicit towerbase(QObject *parent = 0);
    int CoorX,CoorY;
    double angle=30;
    int range;
    int attackpower;
    enemybase* targetEnemy=NULL;
    QVector<bullet*> bulletVec;
    QString PicturePath;
    void Attack(QVector<enemybase*> &enemy);
    double distance(int a,int b,int c,int d);
    int counter=0;//counter/5才攻击一次




signals:

public slots:

};

#endif // TOWERBASE_H
