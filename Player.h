#include "Character.h"
#include "Item.h"
#include "Weapon.h"
class Player: protected Character
{
    private:
        double XP;
        Weapon *Player_Weapon;
        Item *Player_Item;
        long Money;
        int SP;
    public:
        Player(std::string, double, double, double);
        void Show_Info();
        virtual void Attack();
        virtual void Skill();
        void Using_Item();
        virtual void Show_Description();
        virtual void Show_Skill_Description();
};