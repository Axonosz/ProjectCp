#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

Map::Map() {
    const char* temp[6] = {
        "##########",
        "#........#",
        "#..###...#",
        "#........#",
        "#.......O#",
        "##########"
    };

    for(int y=0;y<6;y++)
        for(int x=0;x<10;x++)
            tiles[y][x] = temp[y][x];
}

bool Map::isWall(int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 6)
        return true;
    return tiles[y][x] == '#';
}

bool Map::isExit(int x, int y) {
    return tiles[y][x] == 'O';
}

void Map::draw(Player& p, Enemy& e) {
    for(int y=0;y<6;y++) {
        for(int x=0;x<10;x++) {
            if (x == p.getX() && y == p.getY()) std::cout << 'P';
            else if (x == e.getX() && y == e.getY()) std::cout << 'E';
            else std::cout << tiles[y][x];
        }
        std::cout << '\n';
    }
}
