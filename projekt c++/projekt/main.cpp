#include <QApplication>
#include "myrect.h"
#include <QGraphicsView>
#include <QGraphicsScene>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //tworzymy ekran
    QGraphicsScene * scene= new QGraphicsScene();

    //dodajemy obiek
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    //dodamy obiekt na ekran
    scene->addItem(player);

    //robimy obiekt focusabelnym
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //robimy wyglad
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height() - player->rect().height());


    return a.exec();
}
