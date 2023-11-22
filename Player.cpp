#include"Player.h"
#include<iostream>
#include<iomanip>
Player::Player(std::string name, double maxhp, double atk, double def)
        :Character(name, 1, maxhp, atk, def), XP(0.0), Money(0), SP(0)
{
    this->Player_Item=nullptr;
    this->Player_Weapon=nullptr;
}
void Player::Show_Status()
{
    using namespace std;
    ostringstream test_string[4];
    test_string[0]<<left<<setw(6)<<"\nLevel"<<": "<<left<<setw(9)<<this->getLevel()<<left<<setw(5)<<"XP"<<": "<<this->XP;
    test_string[1]<<left<<setw(6)<<"\nHP"<<": "<<left<<setw(9)<<this->getHP()<<left<<setw(5)<<"MaxHP"<<": "<<this->getMaxHP();
    test_string[2]<<left<<setw(6)<<"\nATK"<<": "<<left<<setw(9)<<this->getATK()<<left<<setw(5)<<"DEF"<<": "<<this->getDEF();
    test_string[3]<<left<<setw(6)<<"\nMoney"<<": $"<<left<<setw(8)<<this->Money<<left<<setw(5)<<"SP"<<": "<<this->SP;
    int max=0;
    for (int i=max+1;i<4;i++)
    {
        if(test_string[max].str().length()<=test_string[i].str().length()) max=i;
    }
    int padding=test_string[max].str().length()-13;
    cout<<"\n\n"<<string(padding/2,'~')<<"PLAYER STATUS"<<string(padding-padding/2,'~');
}   
void Player::Attack(Enemy &e)
{
    e.setHP(e.getHP()-(this->getATK()-e.getDEF()));
}
void Using_Item();
void Show_Description();
void Show_Skill_Description();
void Player::Gain_XP(){

    if() 
}
