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
    public:
        Player(std::string, double, double, double);
        Player(Weapon* weapon);
        void Show_Status();
        void Attack(Enemy&);
        void Skill();
        void Using_Item();
        void Show_Description();
        void Show_Skill_Description();
        void Gain_XP();
        Weapon* getEquippedWeapon();
};
#endif