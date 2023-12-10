#include <QGraphicsScene>
#include <QApplication>
#include "LoseScreen.h"
#include <QFont>
#include "Player.h"
#include "Bullet.h"
#include <QTimer>
#include <QList>
#include <QObject>
#include <QThread>
LoseScreen::LoseScreen(QGraphicsItem *parent): QGraphicsTextItem(parent){
    setPlainText(QString("GAME OVER"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Arial",50));
}
