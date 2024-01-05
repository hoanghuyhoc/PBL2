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

void Area::EnterArea(Enemy* EnemyList, Item* ItemList, Weapon* WeaponList)
{
    Nodes* NodeList=nullptr, *temp=nullptr;
    int encounter_count=0, combat_count=0;
    for(int i=1; i<this->NodeNumber; i++)
    {
        if ((RandomInt(1,3)==3||combat_count>=3)&&encounter_count<2) 
        //Neu du 3 combat lien tiep thi se la Encounter, hoac 2 encounter lien tiep thi la combat 
        {
             //Neu random ra 3 thi se la Encounter (Type=2);
            temp= dynamic_cast<Nodes*>(new Encounter(i));
            combat_count=0; //xoa chuoi Combat
            encounter_count++;
        }
        else 
        {
            temp= dynamic_cast<Nodes*>(new Combat(i,0));
            combat_count++;
            encounter_count=0;
        }
        temp->InsertIntoNodeList(NodeList);
        temp=nullptr;
    }
    temp= dynamic_cast<Nodes*>(new Combat(this->NodeNumber,1));
    temp->InsertIntoNodeList(NodeList);
    system("cls");
    std::cout<<"[GAME] You are entering "<<this->AreaName<<"...";
    Sleep(2000);
    while (NodeList!=nullptr)
    {    
        NodeList->Enter(this->player, EnemyList, this->AreaName, this->Level, ItemList, WeaponList);
        if (NodeList->EnterNext()!=nullptr)
            std::cout<<"[GAME] You are going to the next node...";
        else
            break;
        Sleep(2000);
        NodeList=NodeList->EnterNext();
    }
    std::cout<<"[GAME] Congratulations! You have cleared this Area!";
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
        Area *before=nullptr, *after=List;
        while( (after!=nullptr) && (after->getLevel()<this->Level) ) 
        {
            before=after;
            after=after->EnterNext();
        }
        this->EnterNext()=after;
        if (before==nullptr)
        {
            List=this;
        }
        else 
        {
            before->EnterNext()=this;   
        }
    }
}
std::istream &operator>>(std::istream& input, Area& object)
{
    input>>object.AreaName>>object.NodeNumber>>object.Level;
    return input;
}