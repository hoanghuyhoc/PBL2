#include"Nodes.h"
Nodes::Nodes(int type, int location, Nodes* next_node):Type(type), Location(location) 
{
    this->NextNode=next_node;
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
void Nodes::Encounter(Item* List, Player* player)
{
    std::cout<<"You have entered a shop. Choose the Item available below that you want to buy:\n";
    int search[3]={RandomInt(1,9),RandomInt(1,9),RandomInt(1,9)};
    int choicenumber;
    Item* choice[3]={nullptr,nullptr,nullptr};
    Item* temp=nullptr;
    for (int i=0; i<3; i++)
    {
        temp=List;
        while (temp->EnterNext()!=nullptr&&temp->getID()!=search[i])
        {
            temp=temp->EnterNext();
        }
        choice[i]=temp;
        std::cout<<i+1<<". "<<choice[i]->getName()<<"  |Price: "<<choice[i]->getPrice()<<"$\n";
    }
    std::cout<<"You have "<<player->getMoney()<<"$ left\n";
    std::cout<<"Your choice number is: ";
    std::cin>>choicenumber;
    switch (choicenumber)
    {
        case 1:
        {
            if (player->getMoney()>=choice[0]->getPrice())
            {
                std::cout<<"\nYou have obtained "<<choice[0]->getName()<<std::endl;
                player->equipItem(choice[0]);
                player->getMoney()-=choice[0]->getPrice();
            }
            else std::cout<<"\nYou don't have enough money!\n";
            break;
        }
        case 2:
        {
            if (player->getMoney()>=choice[1]->getPrice())
            {
                std::cout<<"\nYou have obtained "<<choice[1]->getName()<<std::endl;
                player->equipItem(choice[1]);
                player->getMoney()-=choice[1]->getPrice();
            }
            else std::cout<<"\nYou don't have enough money!\n";
            break;
        }
        case 3:
        {
            if (player->getMoney()>=choice[2]->getPrice())
            {
            std::cout<<"\nYou have obtained "<<choice[2]->getName()<<std::endl;
            player->equipItem(choice[2]);
            player->getMoney()-=choice[2]->getPrice();
            }
            break;
        }
    }
}

