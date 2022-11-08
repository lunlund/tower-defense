#ifndef DEFENSETOWER2_H
#define DEFENSETOWER2_H

#include <QObject>
#include"towerbase.h"
class defensetower2 : public towerbase
{
    Q_OBJECT
public:
    explicit defensetower2(QObject *parent = 0);
    //void Attack(QVector<enemybase*> enemy);

signals:

public slots:

};

#endif // DEFENSETOWER2_H
