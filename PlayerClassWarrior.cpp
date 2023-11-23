#include "PlayerClassWarrior.h"
Warrior::Warrior(std::string WarriorName)
        :Player(WarriorName, 100, 20, 5)
{}
void Warrior::Skill()
{

}
void Warrior::Show_Description()
{

}
void Warrior::Show_Skill_Description()
{
        cout << "   WARRIOR'S ULTIMATE [O O O]" << endl;
        cout << "   Deals 200% of ATK as damage to the target and\n   gain a 50% ATK Boost on the next 2 turns.";
}