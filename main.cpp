#include <iostream>
#include <string>
#include <windows.h>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
// #include "Item.h"
// #include "Weapon.h"
#include "PlayerClassAssassin.h"
#include "PlayerClassTank.h"
#include "PlayerClassWarrior.h"
// #include "Area.h"
#include "Menu.h"

#define check_loop if (StartMenuOption==2) continue;

int main()
{
    int StartMenuOption;
    do
    {
        Menu::StartMenu(StartMenuOption);
        if (StartMenuOption==2) break;
        Player *mainplayer=nullptr;
        Menu::StartGame(mainplayer);
        Enemy monster("Siuu",1, 50,10,10,"1 thang ngu", "3108", 175);
        std::cout<<"\nYou have encountered an enemy!\n";
        Menu::BattleScreen(mainplayer, monster,StartMenuOption); check_loop
    } while (StartMenuOption!=2);
    return 0;
}
