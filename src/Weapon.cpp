#include "Weapon.h"

Weapon::Weapon()
        :ID(0), Name(""), bonusHP(0), bonusATK(0), bonusDEF(0), Desc("") 
{
    this->NextWeapon=nullptr;
}
Weapon::Weapon(int id, std::string name, std::string desc, int hp, int atk, int def, Weapon* next)
        : ID(id), Name(name), bonusHP(hp), bonusATK(atk), bonusDEF(def), Desc(desc) 
{
    this->NextWeapon=next;
}

int Weapon::getID()
{
    return this->ID;
}
std::string Weapon::getName()
{
    return this->Name;
}
std::string Weapon::getDesc()
{
    return this->Desc;
}
int Weapon::getBonusHP()
{
    return this->bonusHP;
}
int Weapon::getBonusATK()
{
    return this->bonusATK;
}
int Weapon::getBonusDEF()
{
    return this->bonusDEF;
}
Weapon *&Weapon::EnterNext()
{
    return this->NextWeapon;
}

std::istream &operator>>(std::istream& input, Weapon& obj)
{
    input>>obj.ID>>obj.Name>>obj.bonusHP>>obj.bonusATK>>obj.bonusDEF>>obj.Desc;
    return input;
}
void Weapon::InsertIntoList(Weapon*& List)
{
    if (List==nullptr) List=this;
    else
    {
        Weapon *after=List;
        while( (after->EnterNext()!=nullptr) && (after->getID()<this->ID) ) 
        {
            after=after->EnterNext();
        }
        after->EnterNext()=this;
    }
}