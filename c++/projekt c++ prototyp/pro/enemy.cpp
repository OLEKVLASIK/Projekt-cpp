#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand() ->really large int
#include <QList>
#include "game.h"
#include "bullet.h"
extern Game * game; //zmiena globalna dla zmniejszania zycia

Enemy::Enemy(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    //losowanie grzacza
    int random_number = rand() % 700;
    setPos(random_number,0);

    // rysujemy prostokat
    setPixmap(QPixmap(":/img/img/enemy.png"));//rozmiar

    //polaczamy
    QTimer * moving = new QTimer(this);
    connect(moving,SIGNAL(timeout()),this,SLOT(move()));
    moving->start(30);

    QTimer * shooting = new QTimer(this);
    connect(shooting,SIGNAL(timeout()),this,SLOT(shoot()));
    shooting->start(1000);
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

void Enemy::shoot()
{
    Bullet * bullet = new Bullet("enemy");
    bullet->setPos(x(),y());
    scene()->addItem(bullet);
}
