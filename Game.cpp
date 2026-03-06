
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

Game::Game(){
    std::srand(std::time(0));
    map=new Map(15,15);
    player=new Player(1,1);
    level=1;

    generateLevel();
}

Game::~Game(){

    delete map;
    delete player;

    for(auto e:enemies)
        delete e;
}

void Game::generateLevel(){

    for(auto e:enemies) delete e;
    enemies.clear();

    map->generate();
    player->setPos(1,1);

    int count=level+2;

    for(int i=0;i<count;i++){

        int x,y;

        do{
            x=rand()%map->getWidth();
            y=rand()%map->getHeight();
        }
        while(!map->isWalkable(x,y)||(x==1&&y==1));

        enemies.push_back(new Enemy(x,y));
    }
}

bool Game::enemyAt(int x,int y){

    for(auto e:enemies)
        if(e->isAlive() && e->getX()==x && e->getY()==y)
            return true;

    return false;
}

Enemy* Game::getEnemy(int x,int y){

    for(auto e:enemies)
        if(e->isAlive() && e->getX()==x && e->getY()==y)
            return e;

    return nullptr;
}

void Game::draw(){

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    for(int y=0;y<map->getHeight();y++){

        for(int x=0;x<map->getWidth();x++){

            if(player->getX()==x && player->getY()==y)
                std::cout<<"P";
            else if(enemyAt(x,y))
                std::cout<<"E";
            else
                std::cout<<map->getTile(x,y);
        }

        std::cout<<"\n";
    }

    std::cout<<"HP "<<player->getHP()
             <<" ATK "<<player->getATK()
             <<" MP "<<player->getMP()
             <<" LV "<<level<<"\n";

    std::cout<<"WASD move | i inventory | f skill\n";
}

void Game::playerTurn(){

    char c;
    std::cin>>c;

    if(c=='i'){
        player->showInventory();
        return;
    }

    if(c=='f'){
        player->useSkill();
        return;
    }

    int nx=player->getX();
    int ny=player->getY();

    if(c=='w') ny--;
    if(c=='s') ny++;
    if(c=='a') nx--;
    if(c=='d') nx++;

    if(enemyAt(nx,ny)){

        Enemy* e=getEnemy(nx,ny);

        e->takeDamage(player->getATK());

        if(!e->isAlive()){

            if(rand()%2)
                player->addItem("Potion");
            else
                player->addItem("ManaPotion");
        }

        return;
    }

    if(map->isWalkable(nx,ny))
        player->setPos(nx,ny);
}

void Game::enemyTurn(){

    for(auto e:enemies){

        if(!e->isAlive()) continue;

        int dx=0;
        int dy=0;

        if(std::abs(e->getX()-player->getX()) >
           std::abs(e->getY()-player->getY()))
            dx=(player->getX()>e->getX())?1:-1;
        else
            dy=(player->getY()>e->getY())?1:-1;

        int nx=e->getX()+dx;
        int ny=e->getY()+dy;

        if(nx==player->getX() && ny==player->getY()){

            player->takeDamage(e->getATK());
        }
        else if(map->isWalkable(nx,ny) && !enemyAt(nx,ny)){

            e->setPos(nx,ny);
        }
    }
}

void Game::run(){

    while(player->isAlive()){

        draw();

        playerTurn();

        enemyTurn();

        bool clear=true;

        for(auto e:enemies)
            if(e->isAlive()) clear=false;

        if(clear){

            level++;
            std::cout<<"LEVEL CLEAR\n";

            generateLevel();
        }
    }

    std::cout<<"GAME OVER\n";
}
