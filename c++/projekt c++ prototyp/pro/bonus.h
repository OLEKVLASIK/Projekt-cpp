#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Bonus: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bonus();
};

#endif // BONUS_H
