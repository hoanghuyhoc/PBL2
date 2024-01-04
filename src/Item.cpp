#include "Item.h"

Item::Item(int id, std::string name, int level, int category, int hp, int atk, int def, int price, std::string description, Item* next)
    : ID(id), Name(name), Level(level), Category(category), HP(hp), ATK(atk), DEF(def), Price(price), Description(description) 
{
    this->NextItem=next;
}
Item::Item():ID(0), Name(""), Category(0), HP(0), ATK(0), DEF(0), Price(), Description("")
{
    this->NextItem=nullptr;
}
std::istream &operator>>(std::istream& input, Item& obj)
{
    input>>obj.ID>>obj.Name>>obj.Category>>obj.HP>>obj.ATK>>obj.DEF>>obj.Price>>obj.Description;
    return input;
}
void Item::InsertIntoList(Item*& List)
{
    if (List==nullptr) List=this;
    else
    {
        Item *after=List;
        while( (after->EnterNext()!=nullptr) && (after->getID()<this->ID) ) 
        {
            after=after->EnterNext();
        }
        after->EnterNext()=this;
    }
}
Item*& Item::EnterNext()
{
    return this->NextItem;
}
int Item::getID()
{
    return this->ID;
}
void Item::useItem(Player& this_player)
{
    switch (this->Category)
    {
        case 1:
        {
            this_player.setHP(this_player.getHP()+this->HP);
            break;
        }
        case 2:
        {
            this_player.setATK(this_player.getATK()*(1+((this->ATK)/100)));
            break;
        }
        case 3:
        {
            this_player.setDEF(this_player.getDEF()*(1+((this->DEF)/100)));
            break;
        }
    }
}
std::string Item::getName()
{
    return this->Name;
}
int Item::getPrice()
{
    return this->Price;
}
int Item::getLevel()
{
    return this->Level;
}