#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include<QLabel>
class myLabel : public QLabel
{
    Q_OBJECT
public:
    myLabel();
    //QPixmap pix;
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *event);

signals:
    void clicked();

public slots:

};

#endif // MYLABEL_H
