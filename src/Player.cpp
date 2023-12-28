#include"Player.h"
#include <windows.h>
#include<iostream>
#include<iomanip>
#include"read_description.cpp"
Player::Player(std::string name, int maxhp, int atk, int def, std::string PClass)
        :Character(name, 1, maxhp, atk, def), XP(0.0), Money(0), SP(0),Player_Class(PClass)
{
    // this->Player_Item=nullptr;
    // this->equippedWeapon=nullptr;
}
void Player::Show_Status()
{
    using namespace std;
    ostringstream test_string[4];
    test_string[0]<<left<<setw(6)<<"\nLevel"<<": "<<left<<setw(12)<<this->getLevel()<<left<<setw(5)<<"XP"<<": "<<this->XP;
    test_string[1]<<left<<setw(6)<<"\nHP"<<": "<<left<<setw(12)<<this->getHP()<<left<<setw(5)<<"MaxHP"<<": "<<this->getMaxHP();
    test_string[2]<<left<<setw(6)<<"\nATK"<<": "<<left<<setw(12)<<this->getATK()<<left<<setw(5)<<"DEF"<<": "<<this->getDEF();
    test_string[3]<<left<<setw(6)<<"\nMoney"<<": $"<<left<<setw(11)<<this->Money<<left<<setw(5)<<"SP"<<": "<<this->SP;
    int max=0;
    for (int i=max+1;i<4;i++)
    {
        if(test_string[max].str().length()<=test_string[i].str().length()) max=i;
    }
    int padding=test_string[max].str().length()-13;
    cout<<"\n\n"<<string(padding/2,'~')<<"PLAYER STATUS"<<string(padding-padding/2,'~');
    for (int i=0;i<4;i++)
    {
        cout<<test_string[i].str();
    }
    cout<<endl<<string(padding+13,'~')<<endl;
}   
void Player::Attack(Enemy &e)
{
    int atk=this->getATK(), def=e.getDEF();
    int damage=atk-def;
    e.setHP(e.getHP()-damage);
    std::cout<<"[COMBAT] You used Normal attack and dealt "<<damage<<" Damage to the Enemy!\n";
    Sleep(3000);
}
void Player::Skill(Enemy &e)
{
    int atk=this->getATK(), def=e.getDEF();
    int damage=(atk-def);//*multiplier (dựa trên vũ khí, gây thêm số % damage so với bình thường)
    e.setHP(e.getHP()-damage);
    std::cout<<"[COMBAT] You used Skill and dealt "<<damage<<" Damage to the Enemy!\n";
    Sleep(3000);
}
void Player::Ultimate(Enemy &e)
{
    int atk=this->getATK(), def=e.getDEF();
    int damage=(atk-def);//*multiplier (dựa trên class, gây thêm số % damage so với bình thường)
    e.setHP(e.getHP()-damage);
    std::cout<<"[COMBAT] You used Ultimate and dealt "<<damage<<" Damage to the Enemy!\n";
    Sleep(3000);
}
// void Using_Item();
void Player::Show_Description()
{
    read_txt("Class description\\"+this->Player_Class);
}
void Player::Show_Skill_Description()
{
    read_txt("Skill description\\"+this->Player_Class);
}
void Player::Gain_XP(int xp_gained)
{
    std::cout<<"You gained "<<xp_gained<<" XP !\n";
    Sleep(1500);
    this->XP+=xp_gained;
    while(this->XP>=(this->getLevel()*100))
    {
        this->XP-=(this->getLevel()*100);
        this->setLevel(this->getLevel()+1);
        std::cout<<"Leveled up! Current level: "<<this->getLevel()<<std::endl;
        std::cout<<"XP left to level up: "<<this->XP<<'/'<<this->getLevel()*100<<std::endl;
        Sleep(3000);
    }
}
// void Player::equipWeapon(Weapon& w)
// {
//     this->equippedWeapon=&w;
// }