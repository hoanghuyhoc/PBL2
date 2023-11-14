#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
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
        virtual void Attack()=0;
        virtual void Skill()=0;
        void Using_Item();
        virtual void Show_Description()=0;
        virtual void Show_Skill_Description()=0;
};
#endif