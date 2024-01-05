#include "Combat.h"
Combat::Combat(int type, int location, int combattype)
        :Nodes(type,location), CombatType(combattype)
{}

void Combat::Enter(Enemy* EnemyList)
{
    Enemy* temp=EnemyList, *NotBoss=nullptr;
    while (temp!=nullptr)
    {
        if (temp->IsBoss()==0)
        temp->InsertIntoList(NotBoss);
    }
}