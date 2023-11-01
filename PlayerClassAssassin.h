#include "Player.h"
#include <string>
class Assassin: protected Player
{
    public:
        Assassin();
        void Attack();
        void Skill();
        void Show_Description();
        void Show_Skill_Description();
};