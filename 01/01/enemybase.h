#ifndef ENEMYBASE_H
#define ENEMYBASE_H

#include <QObject>
#include<QString>
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
    //int route;


signals:

public slots:

};

#endif // ENEMYBASE_H
