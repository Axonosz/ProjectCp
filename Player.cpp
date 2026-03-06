
#include "Player.h"
#include <iostream>

Player::Player(int x,int y):Entity(x,y,100){
    atk=12;
    mp=30;
    mpMax=30;
}

int Player::getATK(){return atk;}
int Player::getMP(){return mp;}

void Player::addHP(int v){
    hp+=v;
    if(hp>hpMax) hp=hpMax;
}

void Player::addATK(int v){
    atk+=v;
}

void Player::addItem(std::string item){
    inventory.push_back(item);
}

void Player::showInventory(){

    if(inventory.empty()){
        std::cout<<"Inventory empty\n";
        return;
    }

    std::cout<<"\nInventory\n";

    for(int i=0;i<inventory.size();i++)
        std::cout<<i<<" "<<inventory[i]<<"\n";

    std::cout<<"choose item (-1 cancel): ";

    int id;
    std::cin>>id;

    if(id>=0 && id<inventory.size()){
        if(useItem(id))
            inventory.erase(inventory.begin()+id);
    }
}

bool Player::useItem(int id){

    std::string item=inventory[id];

    if(item=="Potion"){
        addHP(30);
        std::cout<<"Heal 30\n";
        return true;
    }

    if(item=="ManaPotion"){
        mp+=20;
        if(mp>mpMax) mp=mpMax;
        std::cout<<"Mana restored\n";
        return true;
    }

    return false;
}

void Player::useSkill(){

    if(mp<10){
        std::cout<<"Not enough mana\n";
        return;
    }

    mp-=10;
    std::cout<<"Fireball cast!\n";
}
