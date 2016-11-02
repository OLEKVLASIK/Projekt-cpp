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
    MyRect * rect = new MyRect();
    rect->setRect(0,0,100,100);

    //dodamy obiekt na ekran
    scene->addItem(rect);

    //robimy obiekt focusabelnym
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //robimy wyglad
    QGraphicsView * view = new QGraphicsView(scene);

    view->show();

    return a.exec();
}
