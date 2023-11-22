#ifndef ENEMY_H
#define ENEMY_H 
#include"Character.h"
#include"Player.h"
#include <string>
class Enemy: protected Character
{
    private:
        std::string Description;
        std::string Loot;
        std::string Skill;
    public:
        Enemy();
        void Attack();
    friend class Player;
};
#endif