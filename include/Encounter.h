#ifndef ENCOUNTER_H
#define ENCOUNTER_H
#include <sstream>
#include "Nodes.h"
#include "Item.h"
#include "Player.h"
#include "Data.h"
class Encounter : public Nodes
{
    int EncounterType;
    public:
    Encounter(int, int, Nodes*);
    void Enter(Player*, Item*, Weapon*, int);
    void GatheringStormclouds(Player*);
    void MysteriousTrader(Player*, Item*);
    void AnUnexpectedMeetup(Player*);
    void SlumberInTheCabin(Player*);
    void Supplies(Player*);
    void Weaponsmith(Player*, Weapon*);
};
#endif