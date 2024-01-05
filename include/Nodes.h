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
        Nodes(int, int);
        int getType();
        int getLocation();
        virtual void Enter(Player*,std::string, int, int, Item*, Player*);
        Nodes* &EnterNext();
        void InsertIntoNodeList(Nodes *&List);
        friend std::ostream& operator<<(std::ostream&, const Nodes&);
        friend std::istream &operator>>(std::istream&, Nodes&);
};
#endif