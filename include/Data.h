#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <sstream>
namespace Data
{
    template<class C>
    void InputDataFromTxt(std::fstream& FileList, C *&List)
    {
        std::string line;
        while (std::getline(FileList,line))
        {
            std::istringstream inputline(line);
            C* temp=new C();
            inputline>>(*temp);
            temp->InsertIntoList(List);
        }
    }
    template<class C>
    void DeleteData(C *&List)
    {
        C* temp=nullptr;
        while(List!=nullptr)
            {
                temp=List;
                List=List->EnterNext();
                delete temp;
            }
    }
};
#endif