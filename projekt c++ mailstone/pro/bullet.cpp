#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"

extern Game * game;//zmiena globalna ktora jest wykarzystana dla zwiekszania wyniku

Bullet::Bullet(QGraphicsItem *parent):QObject(),QGraphicsRectItem(parent)
{
    // rysujemy prostokat
    setRect(0,0,10,50);//rozmiar

    //polaczamy
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //jezeli strzal ma kolizje z wroge zniszcz
    QList<QGraphicsItem*>colliding_items = collidingItems();

    for(int i=0, n=colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i]))==typeid(Enemy)){
            //zwiekszanie wyniku
            game->score->increase();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //ruch move do gory
    setPos(x(),y()-10);
    if (pos().y() + rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
