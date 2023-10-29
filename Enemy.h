#include"Character.h"
#include <string>
typedef std::string string;
class Enemy: protected Character
{
    string Description;
    string Loot;
    string Skill;
};