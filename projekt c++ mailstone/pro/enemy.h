#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>


class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots: //to znaczy ze ten slot bedzie polaczony z sygmalen move
    void move();
};

#endif // ENEMY_H
