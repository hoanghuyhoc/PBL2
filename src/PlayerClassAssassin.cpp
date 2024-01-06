#include "PlayerClassAssassin.h"
Assassin::Assassin(std::string AssassinName)
        :Player(AssassinName, 80, 30, 2,"Assassin")
{}
Assassin::~Assassin(){}
int Assassin::Ultimate(Enemy& e, int& ultiStatus)
{
    if (RandomInt(0,127)!=MISS)
    {
        int atk=this->getATK(), def=e.getDEF();

        int damage;
        if(atk <= def) damage = 4;
            else damage=(atk-def)*4;// Assassin gây 400% ATK

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
void Assassin::Level_Up()
{
    system("cls");
    this->setLevel(this->getLevel()+1);
    std::cout<<"\nLeveled up! Your level is "<<this->getLevel()<<" !\n";
    Sleep(1000);
    std::cout<<"XP: "<<this->getXP()<<'/'<<this->getLevel()*100<<std::endl;
    Sleep(500);
    std::cout<<"HP : "<<this->getHP()<<" +4\n"; this->setHP(this->getHP()+4);
    std::cout<<"ATK: "<<this->getATK()<<" +3\n"; this->setATK(this->getATK()+3);
    std::cout<<"DEF: "<<this->getDEF()<<" +1\n"; this->setDEF(this->getDEF()+1);
    Sleep(3000);
    system("cls");
}