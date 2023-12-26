#ifndef MENU_H
#define MENU_H
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <iomanip>
#include "Player.h"
#include "PlayerClassAssassin.h"
#include "PlayerClassTank.h"
#include "PlayerClassWarrior.h"
#include "Enemy.h"
namespace Menu
{
    inline int PlayStatus=1;
    void StartMenu(int&);
    void StartGame(Player*&);
    void BattleScreen(Player*&, Enemy);
};
#endif