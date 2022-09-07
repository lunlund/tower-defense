#ifndef ENEMY1_H
#define ENEMY1_H

#include <QObject>
#include"enemybase.h"
class enemy1 : public enemybase
{
    Q_OBJECT
public:
    explicit enemy1(QObject *parent = 0);
    //void Attack(QVector<enemybase>& enemy);

signals:

public slots:

};

#endif // ENEMY1_H
