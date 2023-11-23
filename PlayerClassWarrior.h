#ifndef PLAYERCLASSWARRIOR_H
#define PLAYERCLASSWARRIOR_H
#include "Player.h"
#include <string>
#include <iostream>
class Warrior: protected Player
{
    public:
        Warrior(std::string);
        void Skill();
};
#endif