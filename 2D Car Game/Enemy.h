#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Player.h"

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    Player * player;
    Enemy *enemy;
    bool CanDoDamage=true;
public slots:
    void move();

};

#endif // ENEMY_H
