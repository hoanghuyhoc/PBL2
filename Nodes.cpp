#include"Nodes.h"
Nodes::Nodes(int type, int location):Type(type), Location(location)
{}
Nodes* Nodes::EnterNextNode()
{
    return this->NextNode;
}