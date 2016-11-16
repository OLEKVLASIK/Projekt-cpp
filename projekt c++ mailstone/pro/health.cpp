#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //inicjalizujemy wynik dla 0
    hp = 1;
    //rysujemy text
    setPlainText(QString("Health: ") + QString::number(hp));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    hp-=1;
    setPlainText(QString("Health: ") + QString::number(hp));

}

int Health::getHealth()
{
    return hp;
}
