
#include "Map.h"
#include <cstdlib>

Map::Map(int w,int h){
    width=w;
    height=h;
    grid.resize(h,std::vector<char>(w,'.'));
}

void Map::generate(){

    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){

            if(x==0||y==0||x==width-1||y==height-1)
                grid[y][x]='#';
            else if(rand()%8==0)
                grid[y][x]='#';
            else
                grid[y][x]='.';
        }
    }
}

int Map::getWidth(){return width;}
int Map::getHeight(){return height;}

bool Map::isWalkable(int x,int y){

    if(x<0||y<0||x>=width||y>=height) return false;

    return grid[y][x]=='.';
}

char Map::getTile(int x,int y){
    return grid[y][x];
}
