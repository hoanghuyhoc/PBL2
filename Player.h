#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
class Player: protected Character
{
    private:
        double XP;
        Weapon *equippedWeapon;
        Item *Player_Item;
        long Money;
        int SP;
        std::string Player_Class;
    public:
        Player(std::string, double, double, double, std::string);
        void Show_Status();
        void Attack(Enemy&);
        //virtual void Skill()=0;
        //void Using_Item(); //chắc truy xuất tới hàm dùng item của cái class item
        void Show_Description();
        void Show_Skill_Description();
        void Gain_XP(double);
        void equipWeapon(Weapon&);
};
#endif