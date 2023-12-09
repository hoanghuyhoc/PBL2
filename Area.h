#ifndef AREA_H
#define AREA_H
#include <string>
#include "Player.h"
class Area
{
    private:   
        std::string AreaName;
        int NodeNumber;
        int Level;
        Player *currentPlayer;
        Area *NextArea;
    public:
        Area(std::string, int, int);
        void EnterArea();
        Area* EnterNextArea();
};
#endif