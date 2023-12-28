#ifndef AREA_H
#define AREA_H
#include <string>
#include "Player.h"
#include "Nodes.h"
#include "Menu.h"
#include "Data.h"
#include "randomizer.h"
class Area
{
    private:   
        std::string AreaName;
        int NodeNumber;
        int Level;
        Area *NextArea;
    public:
        Area();
        Area(std::string, int, int, Area*);
        void EnterArea(Player*);
        Area* &EnterNext();
        int getLevel();
        void InsertIntoList(Area* &List);
        friend std::istream& operator>>(std::istream&, Area&);
};
#endif