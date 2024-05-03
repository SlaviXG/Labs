#ifndef DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_VECTORDEQUE_H
#define DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_VECTORDEQUE_H

#include <vector>
#include <iostream>

#include "Point.h"

struct VectorDeque {
    private:
    bool created = false;
    std::vector<Point>* content = nullptr;
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
    ~VectorDeque();
};


#endif //DEQUE_THROUGH_THE_LENGTH_AND_BREADTH_VECTORDEQUE_H
