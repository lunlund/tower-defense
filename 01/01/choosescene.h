#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <QMainWindow>
#include"playscene.h"
class choosescene : public QMainWindow
{
    Q_OBJECT
public:
    explicit choosescene(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    playscene *play;

signals:void back();

public slots:

};

#endif // CHOOSESCENE_H
