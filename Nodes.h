#ifndef NODES_H
#define NODES_H
#include <string>
class Nodes:
{
    private:   
        int Type;
        int Location;
        Nodes *NextNode;
    public:
        Nodes(int, int);
        void Enter();
        Nodes* EnterNextNode();
};
#endif