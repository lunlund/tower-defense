#ifndef BULLET_H
#define BULLET_H

#include <QObject>

class bullet : public QObject
{
    Q_OBJECT
public:
    explicit bullet(QObject *parent = 0);
    int CoorX,CoorY;
    int x,y;
    int signal=4;
    int time=0;
    //QString PicturePath;

signals:

public slots:

};

#endif // BULLET_H
