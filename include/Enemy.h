#ifndef ENEMY_H
#define ENEMY_H 
#include "Character.h"
#include "Player.h"
#include <string>
class Player;
class Enemy: public Character
{
    private:
        int ID;
        int Boss;
        std::string Description;
        int LootID;
        int XP;
        int Money;
        Enemy *NextEnemy;
    public:
        Enemy(std::string, int, int, int, int, int, int, std::string, int, int,int);
        void Attack(Player&);
        std::string Show_Description();
        int getID();
        int Give_XP();
        int Return_Loot();
        int Return_Money();
        int IsBoss();
        Enemy *&EnterNext();
        void InsertIntoList(Enemy*&);
        friend class Player;
};
#endif