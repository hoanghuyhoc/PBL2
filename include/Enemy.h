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
        int LootID;
        int XP;
        int Money;
    public:
        Enemy(std::string, int, int, int, int, std::string, int, int, int);
        void Attack(Player&);
        std::string Show_Description();
        int Give_XP();
        int Return_Loot();
        friend class Player;
};
#endif