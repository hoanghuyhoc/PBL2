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
#include "Nodes.h"
namespace Menu
{
    int StartMenu();
    void StartGame(Player*&);
    void BattleScreen(Player*&, Enemy, std::string, int);
    int ShowBattleStats(Player*&, Enemy, std::string, int);
    void ShowMap(std::string, int, Nodes*, int);
};
#endif