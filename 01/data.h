#ifndef DATA_H
#define DATA_H

#include <QObject>

class gamedata : public QObject
{
    Q_OBJECT
public:
    explicit gamedata(QObject *parent = 0);
public:
    int a[3][5][9];

signals:

public slots:

};

#endif // DATA_H
