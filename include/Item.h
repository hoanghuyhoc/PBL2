#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
class Item
{
    private:
        int ID;
        std::string Name;
        int Category; //1 là HP, 2 là Atk, 3 là DEF
        int HP, ATK, DEF; //ví dụ HP=30 thì hồi 30, còn ATK vs DEF thì ví dụ 30 thì sẽ là tăng 30%
                          // mà m set giá trị cho 1 trong 3 thôi, 2 cái còn lại để 0
        int Price;
        std::string Description; // cái ni ghi ngắn ngắn thôi he, đừng xuống hàng

    public:
        Item(int, std::string , int , int , int , int , int , std::string );
        void useItem();
        friend std::istream &operator>>(std::istream&, Item&);
        void InsertIntoList(Item*&);
};
#endif