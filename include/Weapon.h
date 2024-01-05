#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Player.h"
class Weapon
{
    private:
        int ID;
        std::string Name;
        int bonusHP;
        int bonusATK;
        int bonusDEF;
        int Price;
        std::string Description;
        Weapon *NextWeapon;
    public:
        Weapon(int, const Weapon&);
        Weapon(int, std::string, std::string, int, int, int, int, Weapon*);
        int getID();
        std::string getName();
        std::string getDescription();
        int getBonusHP();
        int getBonusATK();
        int getBonusDEF();
        Weapon*& EnterNext();
        friend std::istream &operator>>(std::istream&, Weapon&);
        void InsertIntoList(Weapon*&);
        int getPrice();
};
#endif