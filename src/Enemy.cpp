#include "Enemy.h"
#include <windows.h>
#include <iostream>
Enemy::Enemy(std::string name, int level, int maxhp, int atk, int def,std::string des, std::string lootid, int xp)
        :Character(name,level,maxhp,atk,def),Description(des), LootID(lootid), XP(xp)
{}
void Enemy::Attack(Player& p)
{
    int atk=this->getATK(), def=p.getDEF();
    int damage=atk*(atk/def);
    p.setHP(p.getHP()-damage);
    std::cout<<"The enemy have inflicted "<<damage<<" damage on your character!\n";
    Sleep(3000);
}
void Enemy::Show_Description()
{
    std::cout<<this->Description;
}
int Enemy::Give_XP()
{
    return this->XP;
}