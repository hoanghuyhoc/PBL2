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