#include "PlayerClassTank.h"
Tank::Tank(std::string TankName)
        :Player(TankName, 150, 10, 10,"Tank")
{}
void Tank::Skill(Enemy& monster)
{
    monster.setHP( this->getATK()*2 - monster.getDEF() );
}