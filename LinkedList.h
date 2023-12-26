#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
class element
{
    public:
        T* data;
        element* next;
        element()
        {
            this->data=nullptr;
            this->next=nullptr;
        }
};
template<typename T>
class LinkedList 
{
    public:
        element<T>* Head;
        element<T>* Tail;
        LinkedList()
        {
            this->Head=nullptr;
            this->Tail=nullptr;
        }
};
#endif