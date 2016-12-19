#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include "button.h"
#include "bonus.h"
#include <QImage>
#include <QBrush>
#include <QKeyEvent>
#include "health.h"

Game::Game(QWidget *parent)
{
      // tworzenie ekranu
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/img/img/sky1.png")));
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
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Statki kosmiczne"));
    QFont titleFont("tahoma",50);
    title->setFont(titleFont);
    int text_xPosition = this->width()/2 - title->boundingRect().width()/2;
    int text_yPosition = 150;
    title->setPos(text_xPosition, text_yPosition);
    scene->addItem(title);



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
    player->setPixmap(QPixmap(":/img/img/player1.png"));
    player->setPos(400,500);

    // zrob kwadrat focusabelnym
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //dodamy obiekt do ekranu
    scene->addItem(player);

    //tworzenie wyniky //zycia
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(0,25);
    scene->addItem(health);

    // wrogi
    QTimer * timer= new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    bonus = new QTimer();
    QObject::connect(bonus,SIGNAL(timeout()),this,SLOT(bonusSpawning()));
    bonus->start(10000);




    loop = new QTimer();
    QObject::connect(loop,SIGNAL(timeout()),this,SLOT(mainLoop()));
    loop->start(500);

    show();

}

void Game::bonusSpawning()
{
    Bonus * bonus = new Bonus();
    scene->addItem(bonus);
}

void Game::mainLoop()
{
        if(health->hp<1)
        {
            scene->clear();
            //setBackgroundBrush(QBrush(QImage(":/img/img/gameover1.jpg")));
            QGraphicsTextItem* title = new QGraphicsTextItem(QString("Game Over"));
            QFont titleFont("tahoma",50);
            title->setFont(titleFont);
            int text_xPosition = this->width()/2 - title->boundingRect().width()/2;
            int text_yPosition = 100;
            title->setPos(text_xPosition, text_yPosition);
            scene->addItem(title);

            QGraphicsTextItem* wynik = new QGraphicsTextItem(QString("Your score is: ")+ QString::number(score->getScore()));
            QFont wynikFont("tahoma",25);
            wynik->setFont(wynikFont);
            int text_xPosition1 = 300;
            int text_yPosition1 = 450;
            wynik->setPos(text_xPosition1, text_yPosition1);
            scene->addItem(wynik);

            bonus->stop();

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

            loop->stop();
        }

}
