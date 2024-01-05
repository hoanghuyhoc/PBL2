#include "Character.h"
Character::Character(std::string name, int level, int maxhp, int atk, int def)
        :Name(name),Level(level), MaxHP(maxhp), HP(maxhp), ATK(atk), DEF(def) 
{}
std::string Character::getName() const
{
    return this->Name;
}
void Character::setName(std::string name)
{
    this->Name=name;
}
void Character::setLevel(int level)
{
    this->Level=level;
}
int Character::getLevel() const
{
    return this->Level;
}
void Character::setMaxHP(int maxhp)
{
    this->MaxHP=maxhp;
}
int Character::getMaxHP() const
{
    return this->MaxHP;
}
void Character::setHP(int hp)
{
    this->HP=hp;
}
int Character::getHP() const
{
    return this->HP;
}
void Character::setATK(int atk)
{
    this->ATK=atk;
}
int Character::getATK() const
{
    return this->ATK;
}
void Character::setDEF(int def)
{
    this->DEF=def;
}
int Character::getDEF() const
{
    return this->DEF;
}