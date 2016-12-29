#include "bonus.h"
#include <stdlib.h>
#include <QMediaPlayer>

Bonus::Bonus()
{
    //losowanie bonusu
    int random_x = rand() % 700;
    int random_y = rand() % 500;
    setPos(random_x,random_y);

    // rysujemy prostokat
    setPixmap(QPixmap(":/img/img/bonus_cherry.png"));;//rozmiar

}
