#include "enemy2.h"

enemy2::enemy2(QObject *parent) :
    enemybase(parent)
{
    speed=5;
    value=10;
    PicturePath=":/game/ConeheadZombie_%1.png";
    CoorX=0;
    CoorY=0;
    health=3000;
    attack=200;
    move=1;
}
