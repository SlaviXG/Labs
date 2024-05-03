#include <iostream>

template <class T> struct NodeList
{
private:
    struct Node
    {
        T* value;
        Node* next;
        Node* prev;
        Node(T value);
    };

    size_t _size;

public:
    Node* head = nullptr;
    Node* tail = nullptr;

    //Constructors / Destructors
    NodeList();
    ~NodeList();

    //Interaction functions
    size_t size();
    bool isEmpty();
    void clear();
    void eraseNode (Node* node);
    void pushFont(T value);
    void pushBack(T value);
    void popFront();
    void popBack();
};

#include "NodeList.hpp"

