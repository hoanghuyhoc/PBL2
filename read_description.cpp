#include<iostream>
#include<fstream>
#include<string>
void read_txt(std::string Player_Class) //Hàm đọc description
{
    std::ifstream description("Character description\\"+Player_Class+".txt");
    std::string str;
    while( !description.eof() )
    {
        std::getline(description,str,'\n');
        std::cout<<str<<std::endl;
    }
    description.close();
}