#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
class Character
{
    private:   
        std::string Name;
        int Level;
        double HP, MaxHP, ATK, DEF;
    public:
        Character(std::string, int, double, double, double);
        std::string getName();
        void setLevel(int);
        int getLevel();
        void setMaxHP(double);
        double getMaxHP();
        void setHP(double);
        double getHP();
        void setATK(double);
        double getATK();
        void setDEF(double);
        double getDEF();
};
#endif