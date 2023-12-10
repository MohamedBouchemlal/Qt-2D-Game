#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QtMath>
#include <stdlib.h>
#include "Game.h"
#include "Enemy.h"
#include "Player.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    int random_number = 130 +rand() % 450;
    setPos(random_number,0);


    setPixmap(QPixmap(":/images/enemyShip.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){

    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (this->pos().y()>=600 && CanDoDamage) {

        game->health->decrease();
        CanDoDamage = false;
        //scene()->removeItem(this);
        //delete this;
    }

    if (qFabs(player->pos().x() - this->pos().x()) < 90 && qFabs(player->pos().y() - this->pos().y()) < 90 && CanDoDamage){

        game->health->decrease();
        CanDoDamage = false;
        scene()->removeItem(this);
        delete this;
    }
}



