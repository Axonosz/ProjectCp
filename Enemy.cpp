#include "Enemy.h"
#include "Map.h"

Enemy::Enemy(int x, int y) : Entity(x,y) {}

void Enemy::update(int px, int py, Map& map) {
    int nx = x;
    int ny = y;

    if (px > x) nx++;
    else if (px < x) nx--;

    if (!map.isWall(nx, ny)) {
        x = nx;
        return;
    }

    if (py > y) ny++;
    else if (py < y) ny--;

    if (!map.isWall(nx, ny)) {
        y = ny;
    }
}
