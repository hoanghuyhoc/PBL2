#ifndef PLAYERCLASSWARRIOR_H
#define PLAYERCLASSWARRIOR_H
#include "Player.h"
#include <string>
class Warrior: protected Player
{
    public:
        Warrior();
        void Attack();
        void Skill();
        void Show_Description();
        void Show_Skill_Description();
};
#endif