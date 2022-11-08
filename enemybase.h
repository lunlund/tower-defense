#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include <QObject>
#include<QVector>
#include<QString>
#include"plants.h"
//#include"playscene.h"
class Plants;
class enemybase : public QObject
{
    Q_OBJECT
public:
    explicit enemybase(QObject *parent = 0);
    double speed;
    QString PicturePath;
    int CoorX;
    int CoorY;
    int health;
    int attack;
    int value;//value是第几张图片
    int route;
    void Attack(QVector<Plants*> &plants);
    bool move=1;
    Plants *targetplant;


signals:

public slots:

};

#endif // ENEMYBASE_H
