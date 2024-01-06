#include "Weapon.h"

Weapon::Weapon(int id, const Weapon& weapon)
        :ID(id), Name(weapon.Name), bonusHP(weapon.bonusHP), bonusATK(weapon.bonusATK), bonusDEF(weapon.bonusDEF), Price(weapon.Price), Description(weapon.Description) 
{
    this->NextWeapon=nullptr;
}
Weapon::Weapon(int id, std::string name, std::string desc, int hp, int atk, int def, int price, Weapon* next)
        : ID(id), Name(name), bonusHP(hp), bonusATK(atk), bonusDEF(def), Price(price), Description(desc) 
{
    this->NextWeapon=next;
}
Weapon::Weapon()
    :ID(0), Name(""), bonusHP(0), bonusATK(0), bonusDEF(0), Price(0), Description("")
{
    this->NextWeapon=nullptr;
}
int Weapon::getID() const
{
    return this->ID;
}
std::string Weapon::getName() const
{
    return this->Name;
}
std::string Weapon::getDescription() const
{
    return this->Description;
}
int Weapon::getBonusHP() const
{
    return this->bonusHP;
}
int Weapon::getBonusATK() const
{
    return this->bonusATK;
}
int Weapon::getBonusDEF() const
{
    return this->bonusDEF;
}
Weapon *&Weapon::EnterNext()
{
    return this->NextWeapon;
}

std::istream &operator>>(std::istream& input, Weapon& obj)
{
    input>>obj.ID>>obj.Name>>obj.bonusHP>>obj.bonusATK>>obj.bonusDEF>>obj.Price>>obj.Description;
    return input;
}
void Weapon::InsertIntoList(Weapon*& List)
{
    if (List==nullptr) List=this;
    else
    {
        Weapon *before=nullptr, *after=List;
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
int Weapon::getPrice() const
{
    return this->Price;
}