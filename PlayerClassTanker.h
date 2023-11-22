#ifndef PLAYERCLASSTANKER_H
#define PLAYERCLASSTANKER_H
#include "Player.h"
#include <string>
class Tanker: protected Player
{
    public:
        Tanker();
        void Attack();
        void Skill();
};
#endif