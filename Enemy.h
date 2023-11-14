#ifndef ENEMY_H
#define ENEMY_H 
#include"Character.h"
#include <string>
typedef std::string string;
class Enemy: protected Character
{
    private:
        string Description;
        string Loot;
        string Skill;
    public:
        Enemy();
        void Attack();
};
#endif