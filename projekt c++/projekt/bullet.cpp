#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>



Bullet::Bullet()
{
    //rysujemy
    setRect(0,0,10,50);

    //polaczamy
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //rych strzalu
    setPos(x(),y()-10);
    if (pos(),y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
