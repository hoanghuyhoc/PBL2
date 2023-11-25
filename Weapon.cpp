#include "Weapon.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

Weapon::Weapon(int id, std::string& name, std::string& desc, int hp, int atk, int def)
        : ID(id), Name(name), Desc(desc), bonusHP(hp), bonusATK(atk), bonusDEF(def) {}

int Weapon::getID()
{
    return this->ID;
};
std::string Weapon::getName()
{
    return this->Name;
};
std::string Weapon::getDesc()
{
    return this->Desc;
};
int Weapon::getBonusHP()
{
    return this->bonusHP;
}
int Weapon::getBonusATK()
{
    return this->bonusATK;
};
int Weapon::getBonusDEF(){
    return this->bonusDEF;
};

std::vector<Weapon> readWeaponsFromFile(std::string& filename) {
    std::vector<Weapon> weapons;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Khong doc duoc file: " << filename << std::endl;
        return weapons;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int id, hp, atk, def;
        std::string name, desc;

        if (iss >> id >> name >> desc >> hp >> atk >> def) {
            weapons.emplace_back(id, name, desc, hp, atk, def);
        } else {
            std::cerr << "Khong doc duoc line: " << line << std::endl;
            // De hanh dong sau khi bao loi, bo qua file hoac thoat vong lap
        }
    }

    file.close();

    return weapons;
}

Weapon getWeaponByID(std::vector<Weapon>& weapons, int targetID) {
    for (auto& weapon : weapons) {
        if (weapon.getID() == targetID) {
            return weapon;
        }
    }

    // Neu khong tim ra ID, dung lenh return vu khi default

}

void processWeaponAndPlayer() {
    std::string filename = "weapons.txt";
    std::vector<Weapon> weapons = readWeaponsFromFile(filename);

    // Lay 1 Weapon thong qua ID, se thay doi sau
    int targetID = 1;
    Weapon targetWeapon = getWeaponByID(weapons, targetID);

    // Tao 1 object Player voi 1 vu khi cho san, se thay doi sau
    Player player(&targetWeapon);

    // Xem weapon dang duoc dung, se thay doi sau
    Weapon* equippedWeapon = player.getEquippedWeapon();
    if (equippedWeapon) {
        std::cout << "Weapon:" << std::endl;
        std::cout << "ID: " << equippedWeapon->getID() << ", Name: " << equippedWeapon->getName()
                  << ", Desc: " << equippedWeapon->getDesc() << ", bonusHP: " << equippedWeapon->getBonusHP()
                  << ", bonusATK: " << equippedWeapon->getBonusATK() << ", bonusDEF: " << equippedWeapon->getBonusDEF()
                  << std::endl;
    } else {
        std::cout << "Khong tim thay Weapon voi ID " << targetID << std::endl;
    }
}
