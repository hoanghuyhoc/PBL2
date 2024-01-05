#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <sstream>
namespace Data
{
    template<class C>
    int InputDataFromTxt(std::string file_name, C *&List)
    {
        std::fstream FileList;
        FileList.open("data\\"+file_name+".txt",std::ios::in);
        if (!FileList.is_open())
        {
            std::cerr<<"Cannot open "+file_name+".txt!\n";
            system("pause");
            return 1;
        }
        std::string line;
        while (std::getline(FileList,line))
        {
            std::istringstream inputline(line);
            C* temp=new C();
            inputline>>(*temp);
            temp->InsertIntoList(List);
        }
        FileList.close();
        return 0;
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