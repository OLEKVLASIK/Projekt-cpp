#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>


Enemy::Enemy(): QObject(),QGraphicsRectItem()
{
    //losowa pozycja
    int random_number = rand() % 600;
    setPos(random_number,0);

    //rysujemy
    setRect(0,0,100,100);

    //polaczamy
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(60);
}

void Enemy::move()
{
    // rych przeciwnika do dolu
    setPos(x(),y()+5);
    if (pos(),y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
