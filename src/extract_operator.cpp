#include "extract_operator.h"
std::istream &operator>>(std::istream& in, std::string& str)
{
    in>>std::ws;
    std::getline(in,str,'.');
    return in;
} 