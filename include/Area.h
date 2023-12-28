#ifndef AREA_H
#define AREA_H
#include <string>
#include "Player.h"
#include "Nodes.h"
#include "Menu.h"
class Area
{
    private:   
        std::string AreaName;
        int NodeNumber;
        int Level;
        Area *NextArea;
    public:
        Area(std::string, int, int, Area*);
        void EnterArea(Player*);
        Area* &EnterNextArea();
        int getLevel();
        void InsertIntoAreaList(Area* &List);
};
#endif