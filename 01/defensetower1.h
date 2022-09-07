#ifndef DEFENSETOWER1_H
#define DEFENSETOWER1_H

#include <QObject>
#include"towerbase.h"
#include<QString>
class defensetower1 : public towerbase
{
    Q_OBJECT
public:
    explicit defensetower1(QObject *parent = 0);
    //QString PicturePath;
    //void Attack(QVector<enemybase*> enemy);

signals:

public slots:

};

#endif // DEFENSETOWER1_H
