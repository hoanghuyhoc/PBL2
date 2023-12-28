#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Player.h"
class Weapon
{
    private:
        int ID;
        std::string Name;
        int bonusHP;
        int bonusATK;
        int bonusDEF;
        std::string Desc;
        Weapon *NextWeapon;
        // Weapon ni tương tự Item luôn nghe
    public:
        Weapon(int, std::string, std::string, int, int, int, Weapon*);
        int getID();
        std::string getName();
        std::string getDesc();
        int getBonusHP();
        int getBonusATK();
        int getBonusDEF();
        Weapon*& EnterNext();
        friend std::istream &operator>>(std::istream&, Weapon&);
        void InsertIntoList(Weapon*&);
};
#endif