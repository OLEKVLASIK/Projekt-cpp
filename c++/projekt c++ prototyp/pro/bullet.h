#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(QString Shooter);
    QString shooter;
public slots: //to znaczy ze ten slot bedzie polaczony z sygmalen move
    void move();
};




#endif // BULLET_H
