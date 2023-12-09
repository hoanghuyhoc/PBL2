#include <iostream>
#include <string>
#include <iomanip>
#include"PlayerClassWarrior.h"
int main()
{
    #define check_loop \
    if (Start_Menu_Option==2)\
    {\
        std::cout<<"end";\
        continue;\
    }
    
    int Start_Menu_Option=0;
    do
    {
        std::cout<<"Input: ";
        std::cin>>Start_Menu_Option;
        check_loop
    } while (Start_Menu_Option!=4);
    
    return 0;
}