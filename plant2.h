#ifndef PLANT2_H
#define PLANT2_H

#include <QObject>
#include"plants.h"
#include<QVector>
#include"bullet.h"

class plant2 : public Plants
{
    Q_OBJECT
public:
    explicit plant2(QObject *parent = 0);
    int value;
    void Attack(QVector<enemybase*> &enemy);

signals:

public slots:

};

#endif // PLANT2_H
