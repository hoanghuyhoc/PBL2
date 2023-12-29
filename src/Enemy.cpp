#include "Enemy.h"
#include <windows.h>
#include <iostream>
Enemy::Enemy(std::string name, int level, int maxhp, int atk, int def,std::string des, int lootid, int xp, int money)
        :Character(name,level,maxhp,atk,def),Description(des), LootID(lootid), XP(xp), Money(money)
{}
void Enemy::Attack(Player& p)
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
int Enemy::Give_XP()
{
    return this->XP;
}
int Enemy::Return_Loot()
{
    return this->LootID;
}