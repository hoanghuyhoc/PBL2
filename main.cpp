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

#define check_loop if (StartMenuOption==2) continue;

int main()
{
    do
    {
        Menu::StartMenu(Menu::PlayStatus);
        if (Menu::PlayStatus==2) break;
        Player *mainplayer=nullptr;
        Menu::StartGame(mainplayer);

        //khởi tạo danh sách Area từ file txt
        std::fstream AreaFileList;
        AreaFileList.open("Area.txt");
        if (!AreaFileList.is_open())
        {
            std::cerr<<"Cannot open data file!\n";
            system("pause");
            return 1;
        }
        std::string line;
        Area* AreaList=nullptr;
        while (std::getline(AreaFileList,line))
        {
            std::istringstream input(line);
            std::string name; 
            int nodenumber, level;
            input>>name>>nodenumber>>level;
            Area* temp=new Area(name,nodenumber,level,nullptr);
            temp->InsertIntoAreaList(AreaList);
        }

        //Chạy từng Area
        while (AreaList!=nullptr)
        {
            AreaList->EnterArea(mainplayer);
            AreaList=AreaList->EnterNextArea();
        }
        //destructor
            //delete AreaList
                while(AreaList!=nullptr)
                {
                    Area* temp=AreaList;
                    AreaList=AreaList->EnterNextArea();
                    delete temp;
                }
        //delete mainplayer;
        delete mainplayer;
    } while (Menu::PlayStatus!=2);
    return 0;
}
