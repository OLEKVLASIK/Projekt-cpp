#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"
#include "bonus.h"

extern Game * game;//zmiena globalna ktora jest wykarzystana dla zwiekszania wyniku

Bullet::Bullet(QString Shooter)
{
    shooter = Shooter;
    // rysujemy prostokat
    setPixmap(QPixmap(":/img/img/shoot.png"));//rozmiar

    //polaczamy
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{


    //jezeli strzal ma kolizje z wroge zniszcz
    if(shooter == "player")
    {
        QList<QGraphicsItem*>colliding_items = collidingItems();

        for(int i=0, n=colliding_items.size(); i<n; i++)
        {
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
        for(int i=0, n=colliding_items.size(); i<n; i++)
        {
            if(typeid(*(colliding_items[i]))==typeid(Bonus)){
                //zwiekszanie wyniku
                game->score->increase();
                game->score->increase();
                game->score->increase();
                game->score->increase();
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
        if (pos().y() + pixmap().height() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else
    {
        QList<QGraphicsItem*>colliding_items = collidingItems();

        for(int i=0, n=colliding_items.size(); i<n; i++){
            if(typeid(*(colliding_items[i]))==typeid(Player)){
                //zwiekszanie wyniku
                game->health->decrease();

                //scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                //delete colliding_items[i];
                delete this;
                return;
            }
        }
        //ruch move do gory
        setPos(x(),y()+25);
        if (pos().y() + pixmap().height() < 0)
        {
            scene()->removeItem(this);
            delete this;
        }

    }



}
