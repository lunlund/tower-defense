#include "plants.h"

double Plants::distance(int a,int b,int c,int d)
{
    return sqrt((c-a)*(c-a)+(d-b)*(d-b));
}
Plants::Plants(QObject *parent) :
    QObject(parent)
{
value=0;
}
void Plants::Attack(QVector<enemybase*> &enemy)
{
    return;
}
