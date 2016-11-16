#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand() ->really large int
#include <QList>
#include "game.h"

extern Game * game; //zmiena globalna dla zmniejszania zycia

Enemy::Enemy(QGraphicsItem *parent):QObject(),QGraphicsRectItem(parent)
{
    //losowanie grzacza
    int random_number = rand() % 700;
    setPos(random_number,0);

    // rysujemy prostokat
    setRect(0,0,100,100);//rozmiar

    //polaczamy
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //ruch wroga do dolu
    setPos(x(),y()+5);

    if (pos().y() > 600)
    {
        game->health->decrease();
        //zmniejszamy wynik zycia

        scene()->removeItem(this);
        delete this;
    }
}
