
#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy: public Entity{
private:
    int atk;

public:
    Enemy(int x,int y);

    int getATK();
};

#endif
