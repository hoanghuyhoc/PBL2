#include "Area.h"


Area::Area(std::string name, int level, double encounterchance)
    : Name(name), Level(level), EncounterChance(encounterchance), CurrentNodeIndex(0) {
    NodeNumber = 5;
    std::srand(std::time(0));  // Initialize random seed
    generateNode();
}

Area::~Area(){}

void Area::setNodeNumber(int nodenumber) {
    this->NodeNumber = nodenumber;
}

int Area::getNodeNumber() {
    return this->NodeNumber;
}

void Area::setLevel(int level) {
    this->Level = level;
}

int Area::getLevel() {
    return this->Level;
}

void Area::generateNode() {
    for (int i = 0; i < NodeNumber; ++i) {
        double randChance = (std::rand() % 100) / 100.0;
        if (i == NodeNumber - 1 && Level == 3) {
            Nodes[i] = '*';  // Boss node
        } else if (i == 0 && Level == 1) {
            Nodes[i] = '+';  // Node đầu tiên của game luôn là Combat
        } else if (randChance < EncounterChance) {
            Nodes[i] = '-';  // Encounter node
        } else {
            Nodes[i] = '+';  // Combat node
        }
    }
}

void Area::EnterArea() {
    std::cout << "Entering Area " << getLevel() << std::endl;
    ShowMap();
}

Area* Area::EnterNextArea() {
    CurrentNodeIndex = 0; // Reset node index
    if (NextArea) {
        NextArea->EnterArea();
        return NextArea;
    } else {
        std::cout << "Victory!" << std::endl; // Victory Screen
        return nullptr;
    }
}

void Area::ShowMap() {
    std::cout << "Player: " << currentPlayer->getName() << " | Level: " 
              << currentPlayer->getLevel() << " | " << currentPlayer->getXP() 
              << " / " << currentPlayer->getLevel()*100 + 1 << " XP\n";
    std::cout << "Area " << getLevel() << "\n";
    std::cout << Area::Name << "\n";
    for (int i = 0; i < NodeNumber; ++i) {
        std::cout << Nodes[i] << " ";
    }
    std::cout << "\nPress any key to proceed...\n";
}

void Area::EnterNode(int nodeIndex) {
    CurrentNodeIndex = nodeIndex;
    char nodeType = Nodes[nodeIndex];
    switch (nodeType) {
        case '+': StartCombat(); break;
        case '-': StartEncounter(); break;
        case '*': StartBossBattle(); break;
        default: std::cout << "Invalid node.\n";
    }
    if (CurrentNodeIndex == NodeNumber - 1) {
        EnterNextArea();
    }
}

void StartCombat(){

}
void StartEncounter(){

}
void StartBossBattle(){

}