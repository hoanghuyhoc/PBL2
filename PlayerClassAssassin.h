#ifndef PLAYERCLASSASSASSIN_H
#define PLAYERCLASSASSASSIN_H
#include "Player.h"
#include <string>
class Assassin: protected Player
{
    public:
        Assassin(std::string);
        void Skill();
};
#endif