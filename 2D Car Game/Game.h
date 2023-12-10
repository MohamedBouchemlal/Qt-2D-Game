#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Enemy.h"
#include <QPushButton>

class Game: public QGraphicsView{
public:
    Game(QWidget* parent=0);

    QGraphicsScene* scene;
    Player* player;
    Enemy* enemy;
    Score* score;
    Health* health;
    QPushButton* startButton;
    QPushButton* quitButton;
    QPushButton* pauseButton;
};

#endif // GAME_H
