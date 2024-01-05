#include"Nodes.h"
Nodes::Nodes(int type, int location):Type(type), Location(location) 
{
    this->NextNode=nullptr;
}
Nodes* &Nodes::EnterNext()
{
    return this->NextNode;
}
void Nodes::Enter(std::string AreaName, int AreaLevel, int NodeNumber, Item* List, Player* this_player)
{
    if(this->Location==1)
    {
        Enemy* enemy=nullptr;
        if(this->Location==NodeNumber) //Node cuoi, gap Boss
        {
            enemy=new Enemy("Boss", AreaLevel, 105+(AreaLevel*9),22+(AreaLevel*9),15+(AreaLevel*9), "An unbelievably powerful giant monster",RandomInt(0,2)*3+AreaLevel, 100+RandomInt(-10,10), RandomInt(7,10) );
        }
        else
        {
            std::string enemyname;
            switch (RandomInt(1,3))
            {
                case 1:
                {
                    enemyname="Slime"; //DEF cao
                    enemy= new Enemy(enemyname,AreaLevel,80+(AreaLevel*10),5+(AreaLevel*8),10+(AreaLevel*9),"An endurable and bold creature",RandomInt(0,2)*3+AreaLevel, 40+RandomInt(-4,4),RandomInt(1,4));
                    break;
                }
                case 2:
                {
                    enemyname="Goblin"; //Dong deu
                    enemy= new Enemy(enemyname,AreaLevel,65+(AreaLevel*9),10+(AreaLevel*9),7+(AreaLevel*9),"An all-round monster",RandomInt(0,2)*3+AreaLevel, 35+RandomInt(-4,4),RandomInt(1,4));
                    break;
                }
                case 3:
                {
                    enemyname="Skeleton"; //ATK cao
                    enemy= new Enemy(enemyname,AreaLevel,50+(AreaLevel*10),15+(AreaLevel*8),5+(AreaLevel*9),"A fragile moving skeleton holding weapons",RandomInt(0,2)*3+AreaLevel, 35+RandomInt(-4,4),RandomInt(1,4));
                    break;
                }
            }
        }
        //Enemy pawn("Enemy",1,(AreaLevel)*2+50,(AreaLevel)*2+10,(AreaLevel)*2+10,"A pawn","01",25*AreaLevel);
        Menu::BattleScreen(this_player, *enemy, AreaName, AreaLevel);
        delete enemy;
    }
    else if (this->Location==2) this->Encounter(List,this_player);
}
void Nodes::InsertIntoNodeList(Nodes *&List)
{
    if (List==nullptr) List=this;
    else
    {
        Nodes *after=List;
        while( (after->EnterNext()!=nullptr) && (after->getLocation()<this->Location) ) 
        {
            after=after->EnterNext();
        }
        after->EnterNext()=this;
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
std::istream &operator>>(std::istream& input, Nodes& object)
{
    input>>object.Type>>object.Location;
    return input;
}


