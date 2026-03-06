
#include "Enemy.h"

Enemy::Enemy(int x,int y):Entity(x,y,40){
    atk=8;
}

int Enemy::getATK(){
    return atk;
}
