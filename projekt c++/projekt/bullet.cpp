#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "enemy.h"
#include <typeinfo>

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
    //if strzal ma kolizje z przeciwnikiem
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0,n=colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //usuwamy ich
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //rych strzalu
    setPos(x(),y()-10);
    if (pos(),y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
