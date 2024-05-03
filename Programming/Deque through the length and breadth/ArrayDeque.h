#ifndef DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_ARRAYDEQUE_H
#define DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_ARRAYDEQUE_H

#include <iostream>

#include "Point.h"

struct ArrayDeque
{
private:
    bool created = false;
    Point* content = nullptr;
    size_t SIZE;
    size_t _size;
    long int start;
    long int end;
    void print_not_created();
    void print_is_full();
    void print_is_empty();
public:
    void create_empty(size_t size, bool logging = true);
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
    ~ArrayDeque();
};


#endif //DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_ARRAYDEQUE_H
