#include "Item.h"

Item::Item(int id, std::string name, int level, int category, int hp, int atk, int def, int price, std::string description, Item* next)
    : ID(id), Name(name), Level(level), Category(category), HP(hp), ATK(atk), DEF(def), Price(price), Description(description) 
{
    this->NextItem=next;
}
Item::Item()
    :ID(0), Name(""), Level(0), Category(0), HP(0), ATK(0), DEF(0), Price(0), Description("")
{
    this->NextItem=nullptr;
}
Item::Item(int id, const Item &item) : ID(id), Name(item.Name), Level(item.Level), Category(item.Category), HP(item.HP), ATK(item.ATK), DEF(item.DEF), Price(item.Price), Description(item.Description)
{
    this->NextItem=nullptr;
}
Item::Item(const Item& item):ID(item.ID), Name(item.Name), Level(item.Level), Category(item.Category), HP(item.HP), ATK(item.ATK), DEF(item.DEF), Price(item.Price), Description(item.Description)
{
    this->NextItem=nullptr;
}
std::istream &operator>>(std::istream& input, Item& obj)
{
    input>>obj.ID>>obj.Name>>obj.Level>>obj.Category>>obj.HP>>obj.ATK>>obj.DEF>>obj.Price>>obj.Description;
    return input;
}
void Item::InsertIntoList(Item*& List)
{
    if (List==nullptr) List=this;
    else
    {
        Item *before=nullptr, *after=List;
        while( (after!=nullptr) && (after->getID()<this->ID) ) 
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
Item*& Item::EnterNext()
{
    return this->NextItem;
}
int Item::getID() const
{
    return this->ID;
}
void Item::useItem(Player& this_player)
{
    switch (this->Category)
    {
        case 1:
        {
            int before_heal=this_player.getHP();
            int after_heal=this_player.getHP()+this->HP;
            if (this_player.getMaxHP()<=after_heal) after_heal=this_player.getMaxHP();
            this_player.setHP(after_heal);
            if (after_heal==before_heal)
                std::cout<<"[COMBAT] Your HP is already full.\n";
            else std::cout<<"[COMBAT] You regained "<<after_heal-before_heal<<" HP!\n";
            Sleep(2000);
            break;
        }
        case 2:
        {
            this_player.setATK(this_player.getATK()*(1+((this->ATK)/100)));
            std::cout<<"[COMBAT] Your attack stat has been boosted!\n";
            Sleep(2000);
            break;
        }
        case 3:
        {
            this_player.setDEF(this_player.getDEF()*(1+((this->DEF)/100)));
            std::cout<<"[COMBAT] Your defense stat has been boosted!\n";
            Sleep(2000);
            break;
        }
    }
}
std::string Item::getName() const
{
    return this->Name;
}
int Item::getPrice() const
{
    return this->Price;
}
int Item::getLevel() const
{
    return this->Level;
}
std::string Item::getDescription() const
{
    return this->Description;
}