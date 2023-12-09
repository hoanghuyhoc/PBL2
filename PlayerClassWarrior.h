#ifndef PLAYERCLASSWARRIOR_H
#define PLAYERCLASSWARRIOR_H
#include "Player.h"
#include <string>
#include <iostream>
#include "Enemy.h"
class Warrior: public Player
{
    public:
        Warrior(std::string);
        void Skill(Enemy&);
};
#endif