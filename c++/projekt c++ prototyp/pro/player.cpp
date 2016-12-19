#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include "enemy.h"
#include "game.h"
#include "QDebug"
extern Game*game;

Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Left)
   {
       if(pos().x() > 0)
       setPos(x()-10,y());
   }
   else if (event->key() == Qt::Key_Right)
   {
       if(pos().x()+100 < 800)
       setPos(x()+10,y());
   }
   else if (event->key() == Qt::Key_Space)
   {
       //tworzymy strzal
       Bullet * bullet = new Bullet("player");
       bullet->setPos(x(),y());
       scene()->addItem(bullet);
   }
}

void Player::spawn()
{
    //tworzymy wroga
    Enemy * enemy= new Enemy();
    scene()->addItem(enemy);
    qDebug()<<"Stworzono";
}
