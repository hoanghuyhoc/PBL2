#include "Area.h"

Area::Area():AreaName(""),NodeNumber(0),Level(0)
{
    this->NextArea=nullptr;
}
Area::Area(std::string name, int nodenumber, int level, Area* Next)
        :AreaName(name), NodeNumber(nodenumber), Level(level)
{
    this->NextArea=Next;
}
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
    Nodes* NodeList=nullptr;
    for(int i=1; i<=this->NodeNumber; i++)
    {
        int type=1, encounter_count=0, combat_count=0;
        if ((RandomInt(1,3)==3||combat_count>=3)&&encounter_count<2) 
        //Neu du 3 combat lien tiep thi se la Encounter, hoac 2 encounter lien tiep thi la combat 
        {
            type=2; //Neu random ra 3 thi se la Encounter (Type=2);
            combat_count=0; //xoa chuoi Combat
            encounter_count++;
        }
        else 
        {
            combat_count++;
            encounter_count=0;
        }
        Nodes* temp= new Nodes(type,i,nullptr);
        temp->InsertIntoNodeList(NodeList);
        type=1;
    }

    while (NodeList!=nullptr)
    {    
        NodeList->Enter(this_player,Area::AreaName,Area::Level);
        if (NodeList->EnterNextNode()!=nullptr)
            std::cout<<"Entering next node...";
        else
            break;
        Sleep(2000);
        NodeList=NodeList->EnterNextNode();
    }
    std::cout<<"Congratulations! You have cleared this Area!";
    Sleep(2000);
}
Area* &Area::EnterNextArea()
{
    return this->NextArea;
}

int Area::getLevel()
{
    return this->Level;
}

void Area::InsertIntoList(Area *&List)
{
    if (List==nullptr) List=this;
    else
    {
        Area *after=List;
        while( (after->EnterNextArea()!=nullptr) && (after->getLevel()<this->Level) ) 
        {
            after=after->EnterNextArea();
        }
        after->EnterNextArea()=this;
    }
}
std::istream &operator>>(std::istream& input, Area& object)
{
    input>>object.AreaName>>object.NodeNumber>>object.Level;
    return input;
}
