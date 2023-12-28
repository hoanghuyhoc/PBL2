#include <iostream>
#include <string>
#include <cstdlib>
#include "Nodes.h"
#include "PlayerClassWarrior.h"
int main()
{
    Nodes* NodeList=nullptr;
    for(int i=1; i<=2; i++)
    {
        Nodes temp(1,i,nullptr);
        std::cout<<"temp: "<<temp;
        temp.InsertIntoNodeList(NodeList);
        std::cout<<"NodeList: "<<(*NodeList);
    }
//     while(NodeList!=nullptr)
//     {
//         std::cout<<NodeList->getLocation()<<std::endl;
//         NodeList=NodeList->EnterNextNode();
//     }

//     while (NodeList!=nullptr)
//     {    
//         NodeList->Enter(this_player,Area::AreaName,Area::Level);
//         std::cout<<"Entering next node...";
//         Sleep(2000);
//         NodeList=NodeList->EnterNextNode();
//     }
//     std::cout<<"Congratulations! You have cleared this Area!";
//     Sleep(2000);
// }
    return 0;
}