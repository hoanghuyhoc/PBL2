#include "Player.h"
#include <string>
class Tanker: protected Player
{
    private:
        std::string Description;
        std::string Skill_Description;
    public:
        Tanker();
        void Attack();
        void Skill();
        void Show_Description();
        void Show_Skill_Description();
};