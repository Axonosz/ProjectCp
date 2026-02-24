#include "Enemy.h"
#include "Map.h"

Enemy::Enemy(int x, int y) : Entity(x,y) {}

void Enemy::update(int px, int py, Map& map) {
    int dx = 0;
    int dy = 0;

    if (px > x) dx = 1;
    else if (px < x) dx = -1;
    else if (py > y) dy = 1;
    else if (py < y) dy = -1;

    int nx = x + dx;
    int ny = y + dy;

    if (!map.isWall(nx, ny)) {
        x = nx;
        y = ny;
    }
}