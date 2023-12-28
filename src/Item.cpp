#include "Item.h"

Item::Item(int id, std::string name, int category, int hp, int atk, int def, int price, std::string description)
    : ID(id), Name(name), Category(category), HP(hp), ATK(atk), DEF(def), Price(price), Description(description) 
{}


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

// std::vector<Item> readItemsFromFile(const std::string& filename) {
//     std::vector<Item> items;

//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         std::cerr << "[ERROR] Loi doc file!\n";
//         return items;
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         std::istringstream iss(line);
//         int id, price, quantity;
//         std::string name, desc, category;

//         if (iss >> id >> name >> desc >> category >> price >> quantity) {
//             items.emplace_back(id, name, desc, category, price, quantity);
//         } else {
//             std::cerr << "[ERROR] Khong doc duoc item ID so: " << line << "\n";
//             // De hanh dong sau khi bao loi, bo qua file hoac thoat vong lap
//         }
//     }
//     file.close();
//     return items;
#ifndef EXTRACT_OP
#define EXTRACT_OP
std::istream &operator>>(std::istream& in, std::string& str)
{
    in>>std::ws;
    std::getline(in,str,'.');
    return in;
} 
#endif
std::istream &operator>>(std::istream& input, Item& obj)
{
    input>>obj.ID>>obj.Name>>obj.Category>>obj.HP>>obj.ATK>>obj.DEF>>obj.Price>>obj.Description;
    return input;
}
void InsertIntoList(Item*&);