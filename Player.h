#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Map;

class Player : public Entity {
public:
    Player(int x, int y);
    bool handleInput(char c, Map& map);
};

#endif
