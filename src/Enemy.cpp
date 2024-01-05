#include "Enemy.h"

Enemy::Enemy(std::string name, int level, int maxhp, int atk, int def, int id, int isboss, std::string des, int xp, int money)
        :Character(name,level,maxhp,atk,def), ID(id), Boss(isboss), Description(des), XP(xp), Money(money)
{
    this->NextEnemy=nullptr;
}

Enemy::Enemy(const Enemy &e, int AreaLevel)
    :Character(e.getName(), AreaLevel, int(e.getHP()+ pow(AreaLevel,0.7)), int(e.getATK()+ pow(AreaLevel,0.7)), int(e.getDEF()+ pow(AreaLevel,0.7))), ID(0), Boss(e.Boss), Description(e.Description), XP(e.XP), Money(e.Money)
{
    this->NextEnemy=nullptr;
}

Enemy::Enemy()
    :Character("", 0, 0, 0, 0),ID(0),Boss(0),Description(""),XP(0), Money(0)
{
    this->NextEnemy=nullptr;
}

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
void Enemy::setMoney(int money)
{
    this->Money=money;
}
int Enemy::Return_Money()
{
    return this->Money;
}
int Enemy::IsBoss()
{
    return this->Boss;
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

std::istream &operator>>(std::istream &input, Enemy &e)
{
    std::string name;
    int hp, atk, def;
    input>>e.ID>>e.Boss>>name>>hp>>atk>>def>>e.Money>>e.Description;
    e.setName(name);
    e.setMaxHP(hp);
    e.setHP(hp);
    e.setATK(atk);
    e.setDEF(def);
    return input;
}
