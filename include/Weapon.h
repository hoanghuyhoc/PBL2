#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Player.h"
class Weapon
{
    private:
        std::string Name;
        int bonusHP;
        int bonusATK;
        int bonusDEF;
        std::string Desc;
        // Weapon ni tương tự Item luôn nghe
    public:
        Weapon(int id, std::string &name, std::string &desc, int hp, int atk, int def);
        int getID();
        std::string getName();
        std::string getDesc();
        int getBonusHP();
        int getBonusATK();
        int getBonusDEF();
        void processWeaponAndPlayer();
};
#endif