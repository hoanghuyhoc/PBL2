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
        int XP;
    public:
        Enemy(std::string, int, int, int, int, std::string, std::string, int);
        void Attack(Player&);
        void Show_Description();
        int Give_XP();
        //void Return_Loot();
        friend class Player;
};
#endif