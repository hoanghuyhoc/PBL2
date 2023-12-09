#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
using namespace std;
class Item
{
    private:
        int ID;
        string Name;
        string Description;
        string Category;
        int Price;
        int Quantity;
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