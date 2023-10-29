#include "Player.h"
#include <string>
class Warrior: protected Player
{
    private:
        std::string Description;
        std::string Skill_Description;
    public:
        Warrior();
        void Attack();
        void Skill();
        void Show_Description();
        void Show_Skill_Description();
};