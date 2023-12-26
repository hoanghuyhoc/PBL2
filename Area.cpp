#include "Area.h"

Area::Area(std::string name, int nodenumber, int level, Area* Next)
        :AreaName(name), NodeNumber(nodenumber), Level(level), NextArea(Next)
{}
// void Area::generateNode()
// {
//     /*
//     int Node[NodeNumber];    // cái này có this-> ở trước ko?
//     int multiCombatNode;     // tính số lượng combat node liên tiếp, nếu combat node xuất hiện liên tiếp 2 lần, node tiếp theo chắc chắn là Encounter
//     for(int i = 0; i < NodeNumber; i++)
//         // ở dòng này cho hàm generate số random 0 và 1, nếu 0 là CombatNode, nếu 1 là Encounter
//         if(Node[i] == 0)
//         {
//             // generate CombatNode
//             multiCombatNode++;
//             if(multiCombatNode >= 2) Node[i++] = 1;
//         }
//         else cout << "Encounter node"; // generate EncounterNode

//         // Thêm hàm set Node cuối cùng trong Area 3 và 5 là Boss Node (Cũng là combat nhưng khác cái tên)
//     */
// }
// void Area::calculateDoubleNodeChance(double doublenodechance)
// {
//     // Ở Area 1, map đơn giản nên doublenodechance = 0
//     // Ở Area 2 -> 5 tỉ lệ tăng dần (20% ở A2, 30% ở A3, 40% ở A4, 50% ở A5)
// }

void Area::EnterArea(Player* this_player)
{
    Nodes node3(1,3,nullptr);
    Nodes node2(1,2,&node3);
    Nodes node1(1,1,&node2);
    Nodes* pointer=&node1;
    while(pointer!=nullptr)
    {
        pointer->Enter(this_player);
        if (Menu::PlayStatus==2) return;
        pointer=pointer->EnterNextNode();
    }
}
Area* Area::EnterNextArea()
{
    return this->NextArea;
}