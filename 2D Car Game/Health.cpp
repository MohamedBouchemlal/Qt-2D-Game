#include <QGraphicsScene>
#include <QApplication>
#include "Health.h"
#include <QFont>
#include "Player.h"
#include "Bullet.h"
#include <QTimer>
#include <QList>
#include "Enemy.h"
#include "Health.h"
#include "Game.h"
#include <QObject>
#include <QThread>
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 3;
    losemsg = new LoseScreen();
     
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("Arial",18));
}

void Health::decrease(){
   health--;
    setPlainText(QString("Health: ") + QString::number(health));
   // if (Enemy().pos().y()==Player().pos().y()) {
    //   decrease();
   // }
   if(health==0){
       scene()->addItem(losemsg);
        losemsg->setPos(200,250);
   }
  if(health<0)
   //    setPlainText(QString("GAME OVER ") );
    //   setDefaultTextColor(Qt::red);
    //   setFont(QFont("Arial",50));
   pause();
}

int Health::getHealth(){
    return health;
}

void Health::pause(){
    QObject().thread()->usleep(10000);
    system("PAUSE");
}
