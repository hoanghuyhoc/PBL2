#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
class Character
{
    private:   
        std::string Name;
        int Level;
        int MaxHP, HP, ATK, DEF;
    public:
        Character(std::string, int, int, int, int);
        std::string getName();
        void setLevel(int);
        int getLevel();
        void setMaxHP(int);
        int getMaxHP();
        void setHP(int);
        int getHP();
        void setATK(int);
        int getATK();
        void setDEF(int);
        int getDEF();
};
#endif