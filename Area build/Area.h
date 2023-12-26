#ifndef AREA_H
#define AREA_H

#include <string>
#include "Player.h"

class Area
{
private:
    std::string Name;
    int NodeNumber;
    int Level;
    double EncounterChance;
    char Nodes[5];  // Lưu trữ node type ('+', '-', '*')
    Player *currentPlayer;
    Area *NextArea;

public:
    Area(std::string, int, double);
    ~Area();
    void setNodeNumber(int);
    int getNodeNumber();
    void setLevel(int);
    int getLevel();
    void generateNode();
    void EnterArea();
    Area* EnterNextArea();
    void ShowMap();
    void EnterNode(int nodeIndex);  // 0 -> 4 là node 1->5
    void StartCombat();
    void StartEncounter();
    void StartBossBattle();
};

#endif
