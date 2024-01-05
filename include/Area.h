#ifndef AREA_H
#define AREA_H
#include <string>
#include "Player.h"
#include "Nodes.h"
#include "Menu.h"
#include "Data.h"
#include "Combat.h"
#include "Encounter.h"
#include "randomizer.h"
#include "extract_operator.h"
class Area
{
    private:   
        std::string AreaName;
        int NodeNumber;
        int Level;
        Player* player;
        Area *NextArea;
    public:
        Area();
        Area(std::string, int, int, Area*);
        void setPlayer(Player*);
        void EnterArea(Enemy*, Item*, Weapon*);
        Area* &EnterNext();
        int getLevel();
        void InsertIntoList(Area* &List);
        friend std::istream& operator>>(std::istream&, Area&);
};
#endif