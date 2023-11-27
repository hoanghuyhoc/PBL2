#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Player.h"

typedef std::string string;
class Weapon
{
private:
    int ID;
    std::string Name;
    std::string Desc;
    int bonusHP;
    int bonusATK;
    int bonusDEF;

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