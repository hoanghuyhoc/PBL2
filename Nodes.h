#ifndef NODES_H
#define NODES_H
#include <string>
#include "Enemy.h"
#include "Player.h"
#include "Menu.h"
class Nodes
{
    private:   
        int Type;
        int Location;
        Nodes *NextNode;
    public:
        Nodes(int, int, Nodes*);
        void Enter(Player*);
        Nodes* EnterNextNode();
};
#endif