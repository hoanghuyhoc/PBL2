#include "PlayerClassWarrior.h"
Warrior::Warrior(std::string WarriorName)
        :Player(WarriorName, 100, 20, 5,"Warrior")
{}
Warrior::~Warrior(){}
void Warrior::Ultimate(Enemy& monster)
{
    monster.setHP( this->getATK()*2 - monster.getDEF() );
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