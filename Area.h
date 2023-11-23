#ifndef AREA_H
#define AREA_H
#include <string>
typedef std::string string;
class Area
{
    private:   
        string Name;
        int NodeNumber;
        int Level;
        double EncounterChance = 0.5, DoubleNodeChance;
        Area *NextArea;
    public:
        Area(string, int, int, double, double);
        string getName();
        void setNodeNumber(int);
        int getNodeNumber();
        void setLevel(int);
        int getLevel();
        void calculateDoubleNodeChance(double);
        void generateNode();    // tiến hành chọn loại Node cho tất cả các Node trong Area đó: Combat / Encounter
        void EnterArea();
        void EnterNextArea();
};
#endif