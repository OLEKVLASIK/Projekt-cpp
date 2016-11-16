#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include "button.h"



Game::Game(QWidget *parent)
{
      // tworzenie ekranu
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    health= new Health();
    health->setPos(health->x(),health->y()+25);

}
    //tworzymy gracza


void Game::display_Menu()
{
    Button* playButton = new Button(QString("Play"));
    int playButton_xPosition = this->width()/2 - playButton->boundingRect().width()/2;
    int playButton_yPosition = 275;
    playButton->setPos(playButton_xPosition, playButton_yPosition);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Quit"));
    int quitButton_xPosition = this->width()/2 - quitButton->boundingRect().width()/2;
    int quitButton_yPosition = 350;
    quitButton->setPos(quitButton_xPosition, quitButton_yPosition);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
}

void Game::start()
{
    scene->clear();

    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(400,500);

    // zrob kwadrat focusabelnym
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //dodamy obiekt do ekranu
    scene->addItem(player);

    //tworzenie wyniky //zycia
    score = new Score();
    scene->addItem(score);

    scene->addItem(health);

    // wrogi
    QTimer * timer= new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();
}
