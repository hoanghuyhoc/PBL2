#ifndef ENEMY_H
#define ENEMY_H 

#include <string>
#include <math.h>
#include <windows.h>
#include <iostream>
#include "Character.h"
#include "Player.h"
#include "extract_operator.h"
class Player;
class Enemy: public Character
{
    private:
        int ID;
        int Boss; //0 if not boss, 1 if boss
        std::string Description;
        int LootID;
        int XP;
        int Money;
        Enemy *NextEnemy;
    public:
        Enemy(std::string, int, int, int, int, int, int, std::string, int, int, int);
        Enemy(const Enemy&, int);
        Enemy();
        void Attack(Player&);
        std::string Show_Description();
        int getID();
        int Give_XP();
        int Return_Loot();
        int Return_Money();
        int IsBoss();
        Enemy *&EnterNext();
        void InsertIntoList(Enemy*&);
        friend std::istream& operator>>(std::istream&, Enemy&);
        friend class Player;
};
#endif