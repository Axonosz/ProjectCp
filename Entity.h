
#ifndef ENTITY_H
#define ENTITY_H

class Entity{
protected:
    int x,y;
    int hp,hpMax;

public:
    Entity(int x,int y,int hp);

    int getX();
    int getY();
    int getHP();

    void setPos(int nx,int ny);

    bool isAlive();
    void takeDamage(int d);
};

#endif
