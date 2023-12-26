#include"Nodes.h"
Nodes::Nodes(int type, int location, Nodes* next_node):Type(type), Location(location), NextNode(next_node) 
{}
Nodes* Nodes::EnterNextNode()
{
    return this->NextNode;
}
void Nodes::Enter(Player* this_player)
{
    Enemy pawn("Pawn",1,60,10,20,"A pawn","01",25);
    Menu::BattleScreen(this_player, pawn);
}