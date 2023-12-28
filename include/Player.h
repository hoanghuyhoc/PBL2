#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
#include <windows.h>
#include <iostream>
#include <iomanip>
#include "src\\read_description.cpp"
class Enemy;
class Player: public Character
{
    private:
        int XP;
        Weapon *Player_Weapon;
        Item *Player_Item;
        long Money;
        int SP;
        std::string Player_Class;
    public:
        Player(std::string, int, int, int, std::string);
        ~Player();
        void Show_Status();
        void Attack(Enemy&);
        virtual void Skill(Enemy&);
        virtual void Ultimate(Enemy&);
        //void Using_Item(); //chắc truy xuất tới hàm dùng item của cái class item
        void Show_Description();
        void Show_Skill_Description();
        void gainXP(int);
        int getXP();
        virtual void Level_Up()=0;
        //void equipWeapon(Weapon&);
        //void useItem(int itemID);
        std::string returnClass();
        friend class Enemy;
};
#endif