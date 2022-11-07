#ifndef ENEMY2_H
#define ENEMY2_H

#include <QObject>
#include"enemybase.h"
class enemy2 : public enemybase
{
    Q_OBJECT
public:
    explicit enemy2(QObject *parent = 0);
    //void Attack(QVector<enemybase>& enemy);

signals:

public slots:

};

#endif // ENEMY2_H
