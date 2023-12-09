#ifndef ENEMY_H
#define ENEMY_H 
#include "Character.h"
#include "Player.h"
#include <string>
class Player;
class Enemy: public Character
{
    private:
        std::string Description;
        std::string LootID;
        double XP;
    public:
        Enemy(std::string, int, double, double, double, std::string, std::string, double);
        void Attack(Player&);
        void Show_Description();
        double Give_XP();
        //void Return_Loot();
        friend class Player;
};
#endif