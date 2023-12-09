#include "Item.h"
#include <fstream>
#include <sstream>
#include <vector>

Item::Item(int id, const string& name, string& desc, string& category, int price, int quantity)
    : ID(id), Name(name), Desc(desc), Category(category), Price(price), Quantity(quantity) {}

int Item::getID()
{
    return ID;
}
string Item::getName()
{ 
    return Name;
}
string Item::getDesc()
{ 
    return Desc; 
}
string Item::getCategory()
{
    return Category;
}
int Item::getPrice()
{ 
    return Price;
}
void Item::setPrice(int price)
{
    this->Price = price;
}
int Item::getQuantity()
{ 
    return Quantity; 
}
void Item::setQuantity(int quantity)
{
    this->Quantity = quantity;
}

// Hieu ung vat pham
void Item::itemEffects() 
{
    switch(itemID){
        case 1:
        {
            // Potion of Healing I: HP +50
            break;
        }
        case 2:
        {
            // Potion of Healing II: HP +100
            break;
        }
        case 3:
        {
            // Potion of Strength I: ATK +20 for 3 turns
            break;
        }
        case 4:
        {
            // Potion of Strength II: ATK +30 for 4 turns
            break;
        }
        case 5:
        {
            // Potion of Defense I: DEF +20 for 4 turns
            break;
        }
        case 6:
        {
            // Potion of Defense II: ATK +30 for 5 turns
            break;
        }
        case 7:
        {
            // 
        }

    }
}

std::vector<Item> readItemsFromFile(const std::string& filename) {
    std::vector<Item> items;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "[ERROR] Loi doc file!\n";
        return items;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, price, quantity;
        std::string name, desc, category;

        if (iss >> id >> name >> desc >> category >> price >> quantity) {
            items.emplace_back(id, name, desc, category, price, quantity);
        } else {
            std::cerr << "[ERROR] Khong doc duoc item ID so: " << line << "\n";
            // De hanh dong sau khi bao loi, bo qua file hoac thoat vong lap
        }
    }
    file.close();
    return items;
}