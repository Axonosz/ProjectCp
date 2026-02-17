#ifndef MAP_H
#define MAP_H

class Player;
class Enemy;

class Map {
private:
    char tiles[6][10];

public:
    Map();
    bool isWall(int x, int y);
    bool isExit(int x, int y);
    void draw(Player& p, Enemy& e);
};

#endif
