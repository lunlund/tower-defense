#include "defensetower2.h"
#include<QtCore/qmath.h>
defensetower2::defensetower2(QObject *parent) :
    towerbase(parent)
{
    PicturePath=":/game/018.png";
    CoorX=0;
    CoorY=0;
    angle=0;
    range=600;
    attackpower=100;
    kind=101;
}
