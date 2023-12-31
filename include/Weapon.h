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
        Weapon();
        int getID() const;
        std::string getName() const;
        std::string getDescription() const;
        int getBonusHP() const;
        int getBonusATK() const;
        int getBonusDEF() const;
        Weapon*& EnterNext();
        friend std::istream &operator>>(std::istream&, Weapon&);
        void InsertIntoList(Weapon*&);
        int getPrice() const;
};
#endif