#ifndef BULLET_H
#define BULLET_H

//#include <QObject>
#include "enemybase.h"
class enemybase;
class bullet : public QObject
{
    Q_OBJECT
public:
    explicit bullet(QObject *parent = 0);
    int CoorX,CoorY;
    int x,y;
    int signal=4;
    int time=0;
    enemybase *targetenemy;
    //QString PicturePath;

signals:

public slots:

};

#endif // BULLET_H
