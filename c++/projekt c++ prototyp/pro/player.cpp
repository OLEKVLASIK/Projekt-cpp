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
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/img/img/fed_laser.wav"));
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

       //muzyka
       if(bulletsound->state() == QMediaPlayer::PlayingState)
       {
           bulletsound->setPosition(0);
       }
       else if(bulletsound->state() == QMediaPlayer::StoppedState)
       {
           bulletsound->play();
       }
   }
}

void Player::spawn()
{
    //tworzymy wroga
    Enemy * enemy= new Enemy();
    scene()->addItem(enemy);
    qDebug()<<"Stworzono";
}
