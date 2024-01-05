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
        std::string getName() const;
        void setName(std::string);
        void setLevel(int);
        int getLevel() const;
        void setMaxHP(int);
        int getMaxHP() const;
        void setHP(int);
        int getHP() const;
        void setATK(int);
        int getATK() const;
        void setDEF(int);
        int getDEF() const;
};
#endif