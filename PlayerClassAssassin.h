#ifndef PLAYERCLASSASSASSIN_H
#define PLAYERCLASSASSASSIN_H
#include "Player.h"
#include <string>
class Assassin: protected Player
{
    public:
        Assassin();
        void Attack();
        void Skill();
};
#endif