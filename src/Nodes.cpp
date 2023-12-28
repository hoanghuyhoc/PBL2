#include"Nodes.h"
Nodes::Nodes(int type, int location, Nodes* next_node):Type(type), Location(location), NextNode(next_node) 
{}
Nodes* &Nodes::EnterNextNode()
{
    return this->NextNode;
}
void Nodes::Enter(Player* this_player, std::string AreaName, int AreaLevel)
{
    Enemy pawn("Enemy",1,(AreaLevel)*2+50,(AreaLevel)*2+10,(AreaLevel)*2+10,"A pawn","01",25*AreaLevel);
    Menu::BattleScreen(this_player, pawn, AreaName, AreaLevel);
}
void Nodes::InsertIntoNodeList(Nodes *&List)
{
    if (List==nullptr) List=this;
    else
    {
        Nodes *after=List;
        while( (after->EnterNextNode()!=nullptr) && (after->getLocation()<this->Location) ) 
        {
            after=after->EnterNextNode();
        }
        after->EnterNextNode()=this;
    }
}
int Nodes::getType()
{
    return this->Type;
}
int Nodes::getLocation()
{
    return this->Location;
}
std::ostream& operator<< (std::ostream& o, const Nodes& n)
{
    o<<"\nType: "<<n.Type<<" Location: "<<n.Location<<"Next pointer: "
    <<((n.NextNode!=nullptr)? 1 :0)<<std::endl;
    return o;
}