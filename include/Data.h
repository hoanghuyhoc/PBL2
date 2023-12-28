#ifndef DATA_CPP
#define DATA_CPP
#include <iostream>
#include <fstream>
#include <sstream>
namespace Data
{
    template<class C>
    void InputDataFromTxt(std::fstream& , C *&);
    // {
    //     std::string line;
    //     {//Skip first line
    //         std::getline(FileList,line);
    //         line="";
    //     }
    //     while (std::getline(FileList,line))
    //     {
    //         std::istringstream inputline(line);
    //         C* temp=new C();
    //         inputline>>(*temp);
    //         temp->InsertIntoList(List);
    //     }
    // }
    template<class C>
    void DeleteData(C *&);
    // {
    //     C* temp=nullptr;
    //     while(List!=nullptr)
    //         {
    //             temp=List;
    //             List=List->EnterNext();
    //             delete temp;
    //         }
    // }
};
#endif