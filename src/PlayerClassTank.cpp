#include "PlayerClassTank.h"
Tank::Tank(std::string TankName)
        :Player(TankName, 150, 10, 10,"Tank")
{}
Tank::~Tank(){}
void Tank::Ultimate(Enemy& monster)
{
    monster.setHP( this->getATK()*2 - monster.getDEF() );
}
void Tank::Level_Up()
{
    this->setLevel(this->getLevel()+1);
    std::cout<<"\nLeveled up!\n";
    Sleep(1000);
    std::cout<<"XP: "<<this->getXP()<<'/'<<this->getLevel()*100<<std::endl;
    Sleep(500);
    std::cout<<"HP : "<<this->getHP()<<" +8\n"; this->setHP(this->getHP()+8);
    std::cout<<"ATK: "<<this->getATK()<<" +1\n"; this->setATK(this->getATK()+1);
    std::cout<<"DEF: "<<this->getDEF()<<" +2\n"; this->setDEF(this->getDEF()+2);
    Sleep(1500);
}