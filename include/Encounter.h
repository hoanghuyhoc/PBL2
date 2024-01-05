#ifndef ENCOUNTER_H
#define ENCOUNTER_H
#include <sstream>
#include "Nodes.h"
#include "Item.h"
#include "Player.h"
#include "Data.h"
#include "Combat.h"
//layer *player, Enemy* EnemyList, std::string AreaName, int AreaLevel
class Encounter : public Nodes
{
    int EncounterType;
    public:
    Encounter(int);
    void Enter(Player*, Enemy*, std::string, int, Item*, Weapon*);
    void GatheringStormclouds(Player*);
    void MysteriousTrader(Player*, Item*);
    void AnUnexpectedMeetup(Player*, Enemy*, std::string, int, Item*, Weapon*);
    void SlumberInTheCabin(Player*);
    void Supplies(Player*);
    void Weaponsmith(Player*, Weapon*);
};
#endif