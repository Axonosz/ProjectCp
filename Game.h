#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Game {
private:
    Map map;
    Player player;
    Enemy enemy;
    bool playerTurn;
    bool running;

    bool checkCollision();

public:
    Game();
    void run();
    void input();
    void update();
    void render();
};

#endif
