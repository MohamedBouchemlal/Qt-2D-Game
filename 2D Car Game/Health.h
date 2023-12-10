#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include "LoseScreen.h"

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
    void pause();
private:
    int health;
     LoseScreen * losemsg;
};

#endif // HEALTH_H
