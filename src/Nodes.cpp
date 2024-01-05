#include"Nodes.h"
Nodes::Nodes(int type, int location):Type(type), Location(location) 
{
    this->NextNode=nullptr;
}
Nodes* &Nodes::EnterNext()
{
    return this->NextNode;
}
void Nodes::InsertIntoNodeList(Nodes *&List)
{
    if (List==nullptr) List=this;
    else
    {
        Nodes *before=nullptr, *after=List;
        while( (after!=nullptr) && (after->getLocation()<this->Location) ) 
        {
            before=after;
            after=after->EnterNext();
        }
        this->EnterNext()=after;
        if (before==nullptr)
        {
            List=this;
        }
        else 
        {
            before->EnterNext()=this;   
        }
    }
}
int Nodes::getType()
{
    return this->Type;
}
int Nodes::getLocation()
{
    return this->Location;
}
// std::ostream& operator<< (std::ostream& o, const Nodes& n)
// {
//     o<<"\nType: "<<n.Type<<" Location: "<<n.Location<<"Next pointer: "
//     <<((n.NextNode!=nullptr)? 1 :0)<<std::endl;
//     return o;
// }
// std::istream &operator>>(std::istream& input, Nodes& object)
// {
//     input>>object.Type>>object.Location;
//     return input;
// }


