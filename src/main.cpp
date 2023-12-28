#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
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
#include "Data.h"
#include "Item.h"

#define check_loop if (StartMenuOption==2) continue;

int main()
{
//Nhap tu Area.txt
    std::fstream AreaFileList;
    AreaFileList.open("area.txt");
    if (!AreaFileList.is_open())
    {
        std::cerr<<"Cannot open data file!\n";
        system("pause");
        return 1;
    }
    Area* AreaList=nullptr;
    Data::InputDataFromTxt<Area>(AreaFileList,AreaList);
    AreaFileList.close();

//Nhap Item tu item.txt
    std::fstream ItemFileList;
    ItemFileList.open("item.txt");
    if (!ItemFileList.is_open())
    {
        std::cerr<<"Cannot open data file!\n";
        system("pause");
        return 1;
    }
    Item* ItemList=nullptr;
    Data::InputDataFromTxt<Item>(ItemFileList,ItemList);
    ItemFileList.close();

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
                AreaList->EnterArea(mainplayer);
                AreaList=AreaList->EnterNext();
            }
        }
        catch(int life)
        {
            if (life==2) continue;
        }
    } while (1);
    //destructor
        //delete AreaList
            Data::DeleteData<Area>(AreaList);
        //delete ItemList
            Data::DeleteData<Item>(ItemList);
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
