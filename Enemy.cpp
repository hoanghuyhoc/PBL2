#include "Enemy.h"
#include <windows.h>
#include <iostream>
Enemy::Enemy(std::string name, int level, double maxhp, double atk, double def,std::string des, std::string lootid, double xp)
        :Character(name,level,maxhp,atk,def),Description(des), LootID(lootid), XP(xp)
{}
void Enemy::Attack(Player& p)
{
    double atk=this->getATK(), def=p.getDEF();
    double damage=atk*(atk/def);
    p.setHP(p.getHP()-damage);
    std::cout<<"The enemy have inflicted "<<damage<<" damage on your character!\n";
    Sleep(3000);
}
void Enemy::Show_Description()
{
    std::cout<<this->Description;
}
double Enemy::Give_XP()
{
    return this->XP;
}