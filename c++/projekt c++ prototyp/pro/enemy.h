#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots: //to znaczy ze ten slot bedzie polaczony z sygmalen move
    void move();
    void shoot();
};

#endif // ENEMY_H
