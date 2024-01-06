#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
#include <windows.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "randomizer.h"
#define MISS 31

class Item;
class Weapon;
class Enemy;
class Player: public Character
{
    private:
        int XP;
        Weapon *Player_Weapon;
        Item *Player_Item;
        int Money=0;
        int SP;
        std::string Player_Class;
    public:
        Player(std::string, int, int, int, std::string);
        virtual ~Player();
        void Show_Status();
        int Attack(Enemy&, int);
        int Skill(Enemy&, int);
        virtual int Ultimate(Enemy&, int&)=0;
        int useItem(); //chắc truy xuất tới hàm dùng item của cái class item
        // void Show_Description();
        // void Show_Skill_Description();
        void gainXP(int);
        int getXP();
        virtual void Level_Up()=0;
        std::string returnClass();
        int getSP();
        void setSP(int);
        void equipWeapon(Weapon*);
        const Weapon* getWeapon();
        void equipItem(Item*);
        const Item *getItem();
        void earnMoney(int);
        int getMoney();
        friend class Enemy;
};
#endif