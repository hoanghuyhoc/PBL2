#include "PlayerClassWarrior.h"
Warrior::Warrior(std::string WarriorName)
        :Player(WarriorName, 100, 20, 5,"Warrior")
{}
void Warrior::Skill(Enemy& monster)
{
    monster.setHP( this->getATK()*2 - monster.getDEF() );
}