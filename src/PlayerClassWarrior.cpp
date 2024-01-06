#include "PlayerClassWarrior.h"
Warrior::Warrior(std::string WarriorName)
        :Player(WarriorName, 100, 20, 5,"Warrior")
{}
Warrior::~Warrior(){}
int Warrior::Ultimate(Enemy& e, int& ultiStatus)
{
    if (RandomInt(0,127)!=MISS) 
    {
        int atk=this->getATK()*2, def=e.getDEF();
        int damage;
        if(atk <= def) damage = 2;
            else damage=atk-def;
        e.setHP(e.getHP()-damage);
        std::cout<<"[COMBAT] You used Ultimate and dealt "<<damage<<" Damage to the Enemy!\n";
        Sleep(1500);
        ultiStatus=1;
        return 1;
    }
    else
    {
        std::cout<<"[COMBAT] Your Ultimate attack missed !!\n";
        Sleep(1500);
        return 0;
    }
}
void Warrior::Level_Up()
{
    this->setLevel(this->getLevel()+1);
    std::cout<<"\nLeveled up!\n";
    Sleep(1000);
    std::cout<<"XP: "<<this->getXP()<<'/'<<this->getLevel()*100<<std::endl;
    Sleep(500);
    std::cout<<"HP : "<<this->getHP()<<" +5\n"; this->setHP(this->getHP()+5);
    std::cout<<"ATK: "<<this->getATK()<<" +2\n"; this->setATK(this->getATK()+2);
    std::cout<<"DEF: "<<this->getDEF()<<" +1\n"; this->setDEF(this->getDEF()+1);
    Sleep(1500);
}