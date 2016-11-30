#include "bonus.h"
#include <stdlib.h>

Bonus::Bonus()
{
    //losowanie bonusu
    int random_x = rand() % 700;
    int random_y = rand() % 500;
    setPos(random_x,random_y);

    // rysujemy prostokat
    setRect(0,0,25,25);//rozmiar
}
