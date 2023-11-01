#include"Player.h"
#include<iostream>
Player::Player(std::string name, double maxhp, double atk, double def)
        :Character(name, 1, maxhp, atk, def), XP(0.0), Money(0), SP(0)
{}
void Player::Show_Info()
{
    std::cout>>

    
}   
virtual void Attack();
virtual void Skill();
void Using_Item();
virtual void Show_Description();
virtual void Show_Skill_Description();