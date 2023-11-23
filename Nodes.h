#ifndef NODES_H
#define NODES_H
#include <string>
#include "Area.h"
typedef std::string string;
class Nodes: public Area 
{
    private:   
        int Type;
        int Location;
        Nodes *NextNode;
    public:
        Nodes(int, int);
        void setType(int);
        int getType();
        void setLocation(int);
        int getLocation(); 
        void Enter();
        void EnterNextNode();
};
#endif