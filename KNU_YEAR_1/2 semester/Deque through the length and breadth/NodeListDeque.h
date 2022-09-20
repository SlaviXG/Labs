#ifndef DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_NODELISTDEQUE_H
#define DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_NODELISTDEQUE_H

#include <iostream>

#include "Point.h"

struct NodeListDeque
{
    private:
    struct Node
    {
        Point* point;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node (Point point)
        {
            this->point = new Point;
            *(this->point) = point;
        }
    };

    Node* head = nullptr;
    Node* tail = nullptr;

    bool created = false;
    size_t _size;

    void print_not_created();
    void print_is_empty();
    public:
    void create_empty(bool logging = true);
    size_t size();
    Point front();
    Point back();
    void append_left(Point);
    void append(Point);
    Point pop_left(bool logging = true);
    Point pop(bool logging = true);
    bool is_empty();
    void clear(bool logging = true);
    void print();
    ~NodeListDeque();
};


#endif //DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_NODELISTDEQUE_H
