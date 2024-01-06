#include "PlayerClassTank.h"
Tank::Tank(std::string TankName)
        :Player(TankName, 150, 10, 10,"Tank")
{}
Tank::~Tank(){}
int Tank::Ultimate(Enemy& monster, int& ultiStatus)
{
    int after_heal=this->getHP()+int(this->getMaxHP()*0.2);
    if (this->getMaxHP()<=after_heal) after_heal=this->getMaxHP();
    this->setHP(after_heal);
    std::cout<<"[COMBAT] You regained "<<after_heal<<" HP and your defense has been boosted!\n";
    Sleep(1500);
    ultiStatus=1;
    return 1;
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
    Sleep(3000);
}