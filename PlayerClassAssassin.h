#ifndef PLAYERCLASSASSASSIN_H
#define PLAYERCLASSASSASSIN_H
#include "Player.h"
#include <string>
class Assassin: public Player
{
    public:
        Assassin(std::string);
        void Ultimate(Enemy&);
};
#endif