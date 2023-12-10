#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>

#include "Enemy.h"

#include <QDebug>
void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }



}

void MyRect::spawn() {
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
