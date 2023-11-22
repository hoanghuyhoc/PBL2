#include "Character.h"
Character::Character(std::string name, int level, double maxhp, double atk, double def)
        :Name(name),Level(level), MaxHP(maxhp), HP(maxhp), ATK(atk), DEF(def) 
{}
std::string Character::getName()
{
    return this->Name;
}
void Character::setLevel(int level)
{
    this->Level=level;
}
int Character::getLevel()
{
    return this->Level;
}
void Character::setMaxHP(double maxhp)
{
    this->MaxHP=maxhp;
}
double Character::getMaxHP()
{
    return this->MaxHP;
}
void Character::setHP(double hp)
{
    this->HP=hp;
}
double Character::getHP()
{
    return this->HP;
}
void Character::setATK(double atk)
{
    this->ATK=atk;
}
double Character::getATK()
{
    return this->ATK;
}
void Character::setDEF(double def)
{
    this->DEF=def;
}
double Character::getDEF()
{
    return this->DEF;
}