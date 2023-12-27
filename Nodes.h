#ifndef NODES_H
#define NODES_H
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Player.h"
#include "Menu.h"
class Nodes
{
    private:   
        int Type; //1 là Combat, 2 là Encounter
        int Location;
        Nodes *NextNode;
    public:
        Nodes(int, int, Nodes*);
        int getType();
        int getLocation();
        void Enter(Player*,std::string, int);
        Nodes* &EnterNextNode();
        void InsertIntoNodeList(Nodes *&List);
        friend std::ostream& operator<<(std::ostream&, const Nodes&);
};
#endif