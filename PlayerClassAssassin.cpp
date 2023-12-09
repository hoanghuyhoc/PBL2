#include "PlayerClassAssassin.h"
Assassin::Assassin(std::string AssassinName)
        :Player(AssassinName, 80, 30, 2,"Assassin")
{}
void Assassin::Skill(Enemy& monster)
{
    monster.setHP( this->getATK()*2 - monster.getDEF() );
}