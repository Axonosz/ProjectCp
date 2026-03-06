
#include "Entity.h"

Entity::Entity(int x,int y,int hp){
    this->x=x;
    this->y=y;
    this->hp=hp;
    this->hpMax=hp;
}

int Entity::getX(){return x;}
int Entity::getY(){return y;}
int Entity::getHP(){return hp;}

void Entity::setPos(int nx,int ny){
    x=nx; y=ny;
}

bool Entity::isAlive(){
    return hp>0;
}

void Entity::takeDamage(int d){
    hp-=d;
    if(hp<0) hp=0;
}
