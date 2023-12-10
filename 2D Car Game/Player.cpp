#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "Health.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){


    // set graphic
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left){
        if (this->pos().x() > 0)
        this->setPos(x()-10,y());
    }
    if (event->key() == Qt::Key_Right){
        if (this->pos().x() + 100 < 800)
        this->setPos(x()+10,y());
               // setRotation(90);
                }
      if(event->key()==Qt::Key_Up) {
         if (this->pos().y()<800)
                 this->setPos(x(),y()-10);
        // setRotation(-90);
      }
      if(event->key()==Qt::Key_Down) {
         if (this->pos().y()<800)
                 this->setPos(x(),y()+10);}
      else if (event->key() == Qt::Key_Space){
             // create a bullet
             Bullet * bullet = new Bullet();
             bullet->setPos(x()+45,y());
             scene()->addItem(bullet);

            }

}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    enemy->player = this;
    scene()->addItem(enemy);
}

