
#ifndef GAME_H
#define GAME_H

#include <vector>

class Map;
class Player;
class Enemy;

class Game{

private:
    Map* map;
    Player* player;
    std::vector<Enemy*> enemies;

    int level;

public:

    Game();
    ~Game();

    void generateLevel();

    bool enemyAt(int x,int y);
    Enemy* getEnemy(int x,int y);

    void draw();

    void playerTurn();
    void enemyTurn();

    void run();
};

#endif
