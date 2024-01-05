#include "Enemy.h"
#include <windows.h>
#include <iostream>
Enemy::Enemy(std::string name, int level, int maxhp, int atk, int def, int id, int isboss, std::string des, int lootid, int xp, int money)
        :Character(name,level,maxhp,atk,def), ID(id), Boss(isboss), Description(des), LootID(lootid), XP(xp), Money(money)
{}

// Enemy::Enemy(std::string, int, int, int, int, int string, int, int, int, int)
// {
// }
void Enemy::Attack(Player &p)
{
    int atk=this->getATK(), def=p.getDEF();
    int damage=(((atk-def)>0)? (atk-def):1 )*( 1+((p.Player_Weapon!=nullptr)?p.Player_Weapon->getBonusDEF():0 )/100 );
    p.setHP(p.getHP()-damage);
    std::cout<<"[COMBAT] The enemy has inflicted "<<damage<<" Damage to you!\n";
    Sleep(3000);
}
std::string Enemy::Show_Description()
{
    return this->Description;
}
int Enemy::getID()
{
    return this->ID;
}
int Enemy::Give_XP()
{
    return this->XP;
}
int Enemy::Return_Loot()
{
    return this->LootID;
}
int Enemy::Return_Money()
{
    return this->Money;
}
Enemy *&Enemy::EnterNext()
{
    return this->NextEnemy;
}
void Enemy::InsertIntoList(Enemy*& List)
{
    if (List==nullptr) List=this;
    else
    {
        Enemy *before=nullptr, *after=List;
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
