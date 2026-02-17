#include "Player.h"
#include "Map.h"

Player::Player(int x, int y) : Entity(x,y) {}

bool Player::handleInput(char c, Map& map) {
    int nx = x;
    int ny = y;

    if (c == 'w') ny--;
    else if (c == 's') ny++;
    else if (c == 'a') nx--;
    else if (c == 'd') nx++;
    else return false;

    if (!map.isWall(nx, ny)) {
        x = nx;
        y = ny;
        return true;
    }
    return false;
}
