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
    std::fstream FileList;
    FileList.open("data\\area.txt",std::ios::in);
    if (!FileList.is_open())
    {
        std::cerr<<"Cannot open area.txt!\n";
        system("pause");
        return 1;
    }
    Area* AreaList=nullptr;
    Data::InputDataFromTxt<Area>(FileList,AreaList);
    FileList.close();

//Nhap Item tu item.txt
    FileList.open("data\\item.txt",std::ios::in);
    if (!FileList.is_open())
    {
        std::cerr<<"Cannot open item.txt!\n";
        system("pause");
        return 1;
    }
    Item* ItemList=nullptr;
    Data::InputDataFromTxt<Item>(FileList,ItemList);
    FileList.close();

//Nhap Weapon tu weapon.txt
    FileList.open("data\\weapon.txt",std::ios::in);
    if (!FileList.is_open())
    {
        std::cerr<<"Cannot open weapon.txt!\n";
        system("pause");
        return 1;
    }
    Weapon* WeaponList=nullptr;
    Data::InputDataFromTxt<Weapon>(FileList,WeaponList);
    FileList.close();

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
