#ifndef DATA_CPP
#define DATA_CPP
#include <iostream>
#include <fstream>
#include <sstream>
namespace Data
{
    template<class C>
    void InputDataFromTxt(std::fstream&, C *&);
    template<class C>
    void DeleteData(C*&);
};
#endif