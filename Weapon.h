#ifndef WEAPON_H
#define WEAPON_H
#include <string>
typedef std::string string;
class Weapon
{
    private:
        int ID;
        string Name;
        string Description;
        double HP,ATK,DEF;
};
#endif