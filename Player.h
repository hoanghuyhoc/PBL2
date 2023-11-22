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
        Weapon *Player_Weapon;
        Item *Player_Item;
        long Money;
        int SP;
    public:
        Player(std::string, double, double, double);
        void Show_Status();
        void Attack(Enemy&);
        virtual void Skill()=0;
        void Using_Item();
        void Show_Description();
        void Show_Skill_Description();
        void Level_Up();
};
#endif