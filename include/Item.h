#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
using namespace std;
class Item
{
    private:
        string Name;
        int Category; //1 là HP, 2 là Atk, 3 là DEF
        int HP, ATK, DEF; //ví dụ HP=30 thì hồi 30, còn ATK vs DEF thì ví dụ 30 thì sẽ là tăng 30%
                          // mà m set giá trị cho 1 trong 3 thôi, 2 cái còn lại để 0
        int Price;
        string Description; // cái ni ghi ngắn ngắn thôi he, đừng xuống hàng
// lập bảng theo thứ tự giống z luôn ha, Name|Category|HP|ATK|DEF|Price|Description
    public:
        Item(int id, const string& name, const string& desc, const string& category, int price, int quantity);
        int getID();
        string getName();
        string getDesc();
        string getCategory();
        int getPrice();
        void setPrice(int);
        int getQuantity();
        void setQuantity(int);
        void useItem();
};
#endif