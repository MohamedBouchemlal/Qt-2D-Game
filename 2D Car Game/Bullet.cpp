#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game;
Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/images/laserGreen.png"));



    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));


    timer->start(50);
}

void Bullet::move(){

    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            game->score->increase();


            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);


            delete colliding_items[i];
            delete this;


            return;
        }
    }

    setPos(x(),y()-40);

    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;}


    }

