
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <vector>
#include <string>

class Player: public Entity{
private:
    int atk;
    int mp;
    int mpMax;

    std::vector<std::string> inventory;

public:
    Player(int x,int y);

    int getATK();
    int getMP();

    void addHP(int v);
    void addATK(int v);

    void addItem(std::string item);
    void showInventory();
    bool useItem(int id);

    void useSkill();
};

#endif
