#include "Player.h"
#include <string>
class Assassin: protected Player
{
    private:
        std::string Description;
        std::string Skill_Description;
    public:
        Assassin();
        void Attack();
        void Skill();
        void Show_Description();
        void Show_Skill_Description();
};