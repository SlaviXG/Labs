#include "VectorDeque.h"

void VectorDeque::create_empty(bool logging)
{
    if(created) this->clear(false);
    if(!created) content = new std::vector <Point>;
    created = true;
    _size = 0;
    if(logging) std::cout << "Successfully created." << std::endl;
}

void VectorDeque::print_not_created()
{
    std::cerr << "Deque is not created." << std::endl;
}

void VectorDeque::print_is_empty()
{
    std::cerr << "Deque is empty." << std::endl;
}

size_t VectorDeque::size()
{
    if(created) return _size;
    print_not_created();
    return 0;
}

Point VectorDeque::front()
{
    if(created)
    {
        if(_size) return content->front();
        else print_is_empty();
    }
    else print_not_created();

    return Point();
}

Point VectorDeque::back()
{
    if(created)
    {
        if(_size) return content->back();
        else print_is_empty();
    }
    else print_not_created();

    return Point();
}

void VectorDeque::append_left(Point point)
{
    if(created)
    {
        content->insert(content->begin(), point);
        _size++;
    }
    else print_not_created();
}

void VectorDeque::append(Point point)
{
    if(created)
    {
        content->push_back(point);
        _size++;
    }
    else print_not_created();
}

bool VectorDeque::is_empty()
{
    if(created) return (bool) !_size;
    print_not_created();
    return true;
}

Point VectorDeque::pop_left(bool logging)
{
    if(created)
    {
        if(_size)
        {
            Point p = *(content->begin());
            content->erase(content->begin());
            _size--;
            return p;
        }
        else
        {
            if(logging) print_is_empty();
        }
    }
    else print_not_created();

    return Point();
}

Point VectorDeque::pop(bool logging)
{
    if(created)
    {
        if(_size)
        {
            Point p = content->back();
            content->pop_back();
            _size--;
            return p;
        }
        else
        {
            if(logging) print_is_empty();
        }
    }
    else print_not_created();

    return Point();
}

void VectorDeque::clear(bool logging)
{
    if(created)
    {
        content->clear();
        _size = 0;
        if(logging) std::cout << "Cleared." << std::endl;
    }
    else print_not_created();
}

void VectorDeque::print()
{
    if(created)
    {
        std::cout << "Points in the amount of " << _size << std::endl;
        for(size_t i = 0; i < _size; i++)
        {
            std::cout << "-----------------------------------" << std::endl;
            std::cout << (*content)[i];
            std::cout << "-----------------------------------" << std::endl;
        }
    }
    else print_not_created();
}

VectorDeque::~VectorDeque()
{
    delete content;
}


