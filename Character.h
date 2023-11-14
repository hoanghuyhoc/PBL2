#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
typedef std::string string;
class Character
{
    private:   
        string Name;
        int Level;
        double HP, MaxHP, ATK, DEF;
    public:
        Character(string, int, double, double, double);
        string getName();
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