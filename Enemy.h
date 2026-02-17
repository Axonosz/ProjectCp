#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Map;

class Enemy : public Entity {
public:
    Enemy(int x, int y);
    void update(int px, int py, Map& map);
};

#endif
