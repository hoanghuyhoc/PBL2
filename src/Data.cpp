#include "Data.h"
template<class C>
void Data::InputDataFromTxt(std::fstream& FileList, C *&List)
{
    std::string line;
    {//Skip first line
        std::getline(FileList,line);
        line="";
    }
    while (std::getline(FileList,line))
    {
        std::istringstream input(line);
        C* temp=new C();
        input>>(*temp);
        temp->InsertIntoList(List);
    }
}