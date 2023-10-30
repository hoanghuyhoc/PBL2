#include "Character.h"
#include "Item.h"
#include "Weapon.h"
class Player: protected Character
{
    private:
        double XP;
        Weapon Player_Weapon;
        Item Player_Item;
        double Money;
        int SP;
    public:
        void Show_Info();
        virtual void Attack();
        virtual void Skill();
        void Using_Item();
};