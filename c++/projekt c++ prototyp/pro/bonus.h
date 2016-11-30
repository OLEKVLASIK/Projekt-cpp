#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Bonus: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bonus();
};

#endif // BONUS_H
