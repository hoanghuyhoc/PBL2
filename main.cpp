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
#include "Menu.h"
#include "Area.h"
#include "Nodes.h"

#define check_loop if (StartMenuOption==2) continue;

int main()
{
    do
    {
        Menu::StartMenu(Menu::PlayStatus);
        if (Menu::PlayStatus==2) break;
        Player *mainplayer=nullptr;
        Menu::StartGame(mainplayer);
        Area Area1("Area1",3,1,nullptr);
        Area1.EnterArea(mainplayer);
    } while (Menu::PlayStatus!=2);
    return 0;
}
