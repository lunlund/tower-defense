#ifndef PLANT1_H
#define PLANT1_H

#include <QObject>
#include "plants.h"

class plant1 : public Plants
{
    Q_OBJECT
public:
    explicit plant1(QObject *parent = 0);

signals:

public slots:

};

#endif // PLANT1_H
