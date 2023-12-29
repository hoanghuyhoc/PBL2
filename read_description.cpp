#ifndef READ_DESCRIPTION_CPP
#define READ_DESCRIPTION_CPP
#include<iostream>
#include<fstream>
#include<string>
void read_txt(std::string file) //Hàm đọc description
{
    std::ifstream description(file+".txt");
    std::string str;
    while( !description.eof() )
    {
        std::getline(description,str,'\n');
        std::cout<<str<<std::endl;
    }
    description.close();
}
#endif