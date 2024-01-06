#ifndef PLAYERCLASSASSASSIN_H
#define PLAYERCLASSASSASSIN_H
#include "Player.h"
#include <string>
#include <iostream>
#include "Enemy.h"
class Assassin: public Player
{
    public:
        Assassin(std::string);
        ~Assassin();
        int Ultimate(Enemy&, int&);
        void Level_Up();
};
#endif