#ifndef ITEM_H
#define ITEM_H
#include <string>
typedef std::string string;
class Item
{
    private:
        int ID;
        string Name;
        string Description;
        string Category;
        int price;
};
#endif