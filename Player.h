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
};