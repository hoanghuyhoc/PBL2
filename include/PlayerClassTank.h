#ifndef PLAYERCLASSTANKER_H
#define PLAYERCLASSTANKER_H
#include "Player.h"
#include <string>
#include <iostream>
#include "Enemy.h"
class Tank: public Player
{
    public:
        Tank(std::string);
        ~Tank();
        void Ultimate(Enemy&);
        void Level_Up();
};
#endif