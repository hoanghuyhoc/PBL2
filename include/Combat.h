#ifndef COMBAT_H
#define COMBAT_H

#include "Nodes.h"
class Combat:public Nodes
{
    int CombatType; //0 la danh thuong, 1 la danh boss
    public:
    Combat(int, int);
    void Enter(Player*, Enemy*, std::string, int, Item*, Weapon*);
};

#endif