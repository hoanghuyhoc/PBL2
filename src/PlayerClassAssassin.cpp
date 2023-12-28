#include "PlayerClassAssassin.h"
Assassin::Assassin(std::string AssassinName)
        :Player(AssassinName, 80, 30, 2,"Assassin")
{}
Assassin::~Assassin(){}
void Assassin::Ultimate(Enemy& monster)
{
    monster.setHP( this->getATK()*2 - monster.getDEF() );
}
void Assassin::Level_Up()
{
    this->setLevel(this->getLevel()+1);
    std::cout<<"\nLeveled up!\n";
    Sleep(1000);
    std::cout<<"XP: "<<this->getXP()<<'/'<<this->getLevel()*100<<std::endl;
    Sleep(500);
    std::cout<<"HP : "<<this->getHP()<<" +4\n"; this->setHP(this->getHP()+4);
    std::cout<<"ATK: "<<this->getATK()<<" +3\n"; this->setATK(this->getATK()+3);
    std::cout<<"DEF: "<<this->getDEF()<<" +1\n"; this->setDEF(this->getDEF()+1);
    Sleep(1500);
}