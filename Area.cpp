#include "Area.h"

Area::Area(string name, int nodenumber, int level, double encounterchance, double doublenodechance)
        :Name(name), NodeNumber(nodenumber), Level(level), EncounterChance(encounterchance), DoubleNodeChance(doublenodechance)
        {}
Area::~Area(){}
void Area::setNodeNumber(int nodenumber)
{
    this->NodeNumber = nodenumber;
}
int Area::getNodeNumber()
{
    return this->NodeNumber;
}
void Area::setLevel(int level)
{
    this->Level = level;
}
int Area::getLevel()
{
    return this->Level;
}
void Area::generateNode()
{
    int Node[NodeNumber];    // cái này có this-> ở trước ko?
    int multiCombatNode;     // tính số lượng combat node liên tiếp, nếu combat node xuất hiện liên tiếp 2 lần, node tiếp theo chắc chắn là Encounter
    for(int i = 0; i < NodeNumber; i++)
        // ở dòng này cho hàm generate số random 0 và 1, nếu 0 là CombatNode, nếu 1 là Encounter
        if(Node[i] == 0)
        {
            // generate CombatNode
            multiCombatNode++;
            if(multiCombatNode >= 2) Node[i++] = 1;
        }
        else cout << "Encounter"; // generate 1 EncounterNode

        // Thêm hàm set Node cuối cùng trong Area 3 và 5 là Boss Node (Cũng là combat nhưng khác cái tên)
}
void Area::calculateDoubleNodeChance(double doublenodechance)
{
    // Ở Area 1, map đơn giản nên doublenodechance = 0
    // Ở Area 2 -> 5 tỉ lệ tăng dần (20% ở A2, 30% ở A3, 40% ở A4, 50% ở A5)
}

void Area::EnterArea()
{

}
void Area::EnterNextArea()
{

}