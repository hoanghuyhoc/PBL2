#include "Area.h"

Area::Area():AreaName(""),NodeNumber(0),Level(0)
{
    this->NextArea=nullptr;
    this->player=nullptr;
}
Area::Area(std::string name, int nodenumber, int level, Area* Next)
        :AreaName(name), NodeNumber(nodenumber), Level(level)
{
    this->NextArea=Next;
    this->player=nullptr;
}
void Area::setPlayer(Player* player1)
{
    this->player=player1;
}

void Area::EnterArea(Item* List)
{
    Nodes* NodeList=nullptr;
    for(int i=1; i<=this->NodeNumber; i++)
    {
        int type=1, encounter_count=0, combat_count=0;
        if ((RandomInt(1,2)==3||combat_count>=3)&&encounter_count<2) 
        //Neu du 3 combat lien tiep thi se la Encounter, hoac 2 encounter lien tiep thi la combat 
        {
            type=2; //Neu random ra 3 thi se la Encounter (Type=2);
            combat_count=0; //xoa chuoi Combat
            encounter_count++;
        }
        else 
        {
            combat_count++;
            encounter_count=0;
        }
        Nodes* temp= new Nodes(type,i,nullptr);
        temp->InsertIntoNodeList(NodeList);
        type=1;
    }
    system("cls");
    std::cout<<"You are entering "<<this->AreaName<<"...";
    Sleep(3000);
    while (NodeList!=nullptr)
    {    
        NodeList->Enter(this->player,this->AreaName,this->Level,this->NodeNumber,List,this->player);
        if (NodeList->EnterNext()!=nullptr)
            std::cout<<"Entering next node...";
        else
            break;
        Sleep(2000);
        NodeList=NodeList->EnterNext();
    }
    std::cout<<"Congratulations! You have cleared this Area!";
    Sleep(2000);
}
Area* &Area::EnterNext()
{
    return this->NextArea;
}

int Area::getLevel()
{
    return this->Level;
}

void Area::InsertIntoList(Area *&List)
{
    if (List==nullptr) List=this;
    else
    {
        Area *after=List;
        while( (after->EnterNext()!=nullptr) && (after->getLevel()<this->Level) ) 
        {
            after=after->EnterNext();
        }
        after->EnterNext()=this;
    }
}
std::istream &operator>>(std::istream& input, Area& object)
{
    input>>object.AreaName>>object.NodeNumber>>object.Level;
    return input;
}