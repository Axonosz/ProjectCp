
#ifndef MAP_H
#define MAP_H

#include <vector>

class Map{
private:
    int width,height;
    std::vector<std::vector<char>> grid;

public:
    Map(int w,int h);

    void generate();

    int getWidth();
    int getHeight();

    bool isWalkable(int x,int y);

    char getTile(int x,int y);
};

#endif
