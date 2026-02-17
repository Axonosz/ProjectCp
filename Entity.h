#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    int x, y;

public:
    Entity(int x, int y);
    int getX();
    int getY();
};

#endif
