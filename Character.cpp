#include "Character.h"
Character::Character(std::string name, int level, int maxhp, int atk, int def)
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
void Character::setMaxHP(int maxhp)
{
    this->MaxHP=maxhp;
}
int Character::getMaxHP()
{
    return this->MaxHP;
}
void Character::setHP(int hp)
{
    this->HP=hp;
}
int Character::getHP()
{
    return this->HP;
}
void Character::setATK(int atk)
{
    this->ATK=atk;
}
int Character::getATK()
{
    return this->ATK;
}
void Character::setDEF(int def)
{
    this->DEF=def;
}
int Character::getDEF()
{
    return this->DEF;
}