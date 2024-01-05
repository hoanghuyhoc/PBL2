#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Weapon.h"
#include "PlayerClassAssassin.h"
#include "PlayerClassTank.h"
#include "PlayerClassWarrior.h"
#include "Menu.h"
#include "Area.h"
#include "Nodes.h"
#include "Data.h"
#include "Item.h"

int main()
{
//Nhap tu Area.txt
    Area* AreaList=nullptr;
    if(Data::InputDataFromTxt<Area>("area",AreaList))
        return 1;

//Nhap Item tu item.txt
    Item* ItemList=nullptr;
    if(Data::InputDataFromTxt<Item>("item",ItemList))
        return 1;

//Nhap Weapon tu weapon.txt
    Weapon* WeaponList=nullptr;
    if(Data::InputDataFromTxt<Weapon>("weapon",WeaponList))
        return 1;

//Nhap Enemy tu enemy.txt
    Enemy* EnemyList=nullptr;
    if(Data::InputDataFromTxt<Enemy>("enemy",EnemyList))
        return 1;

//Bat dau tro choi
    Player *mainplayer=nullptr;
    do
    {
        if (Menu::StartMenu()==2) break;
        Menu::StartGame(mainplayer);

        //Chạy từng Area
        try
        {
            while (AreaList!=nullptr)
            {
                AreaList->setPlayer(mainplayer);
                AreaList->EnterArea(ItemList);
                AreaList->setPlayer(nullptr);
                AreaList=AreaList->EnterNext();
            }
        }
        catch(int progress)
        {
            continue;
        }
    } while (1);
//destructor
    //delete AreaList
        Data::DeleteData<Area>(AreaList);
    //delete ItemList
        Data::DeleteData<Item>(ItemList);
    //delete WeaponList
        Data::DeleteData<Weapon>(WeaponList);
    //delete mainplayer
        if (mainplayer->returnClass()=="Warrior")
            delete dynamic_cast<Warrior*>(mainplayer);
        else if (mainplayer->returnClass()=="Assassin")
            delete dynamic_cast<Assassin*>(mainplayer);
        else if (mainplayer->returnClass()=="Tank")
            delete dynamic_cast<Tank*>(mainplayer);
        mainplayer=nullptr;
    return 0;
}
