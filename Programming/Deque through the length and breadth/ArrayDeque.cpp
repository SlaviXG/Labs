#include "ArrayDeque.h"

void ArrayDeque::print_not_created()
{
    std::cerr << "Deque is not created." << std::endl;
}

void ArrayDeque::print_is_full()
{
    std::cerr << "Deque is full." << std::endl;
}

void ArrayDeque::print_is_empty()
{
    std::cerr << "Deque is empty." << std::endl;
}

void ArrayDeque::create_empty(size_t size, bool logging)
{
    if(created) this->clear(false);
    SIZE = size;
    if(!created) content = new Point [SIZE];
    _size = 0;
    start = end = 0;
    created = true;
    if(logging) std::cout << "Successfully created." << std::endl;
}

size_t ArrayDeque::size()
{
    if(created) return _size;
    print_not_created();
    return 0;
}

Point ArrayDeque::front()
{
    if(created)
    {
        if(_size) return content[start];
        else print_is_empty();
    }
    else print_not_created();

    return Point();
}

Point ArrayDeque::back()
{
    if(created)
    {
        if (_size) return content[end];
        else print_is_empty();
    }
    else print_not_created();

    return Point();
}

void ArrayDeque::append_left(Point point)
{
    if(created)
    {
        if(_size == SIZE) print_is_full();
        else if(_size == 0)
        {
            content[start] = point;
            _size++;
        }
        else
        {
            if(start == 0)
            {
                start = SIZE - 1;
                content[start] = point;
                _size++;
            }
            else
            {
                start--;
                content[start] = point;
                _size++;
            }
        }
    }
    else print_not_created();
}

void ArrayDeque::append(Point point)
{
    if(created)
    {
        if(_size == SIZE) print_is_full();
        else if(_size == 0)
        {
            content[end] = point;
            _size++;
        }
        else
        {
            if(end == SIZE - 1)
            {
                end = 0;
                content[end] = point;
                _size++;
            }
            else
            {
                end++;
                content[end] = point;
                _size++;
            }
        }
    }
    else print_not_created();
}

Point ArrayDeque::pop_left(bool logging)
{
    if(created)
    {
        if(_size)
        {
            Point p = content[start];
            if(start == end) _size--;
            else
            {
                if(start == SIZE - 1)
                {
                    start = 0;
                    _size--;
                }
                else
                {
                    start++;
                    _size--;
                }
            }
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

Point ArrayDeque::pop(bool logging)
{
    if(created)
    {
        if(_size)
        {
            Point p = content[end];
            if(start == end) _size--;
            else
            {
                if(end == 0)
                {
                    end = SIZE - 1; _size--;
                }
                else
                {
                    end--;
                    _size--;
                }
            }
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

bool ArrayDeque::is_empty()
{
    if(created) return (bool) !_size;
    print_not_created();
    return true;
}

void ArrayDeque::clear(bool logging)
{
    if(created)
    {
        _size = 0;
        start = end = 0;
        if(logging) std::cout << "Cleared." << std::endl;
    }
    else print_not_created();
}

void ArrayDeque::print()
{
    if(created)
    {

        std::cout << "Points in the amount of " << _size << std::endl;

        size_t em_size = _size;
        long em_start = start;
        long em_end = end;

        while(em_size)
        {
            Point p = content[em_start];
            if(em_start == em_end) em_size--;
            else
            {
                if(em_start == SIZE - 1)
                {
                    em_start = 0;
                    em_size--;
                }
                else
                {
                    em_start++;
                    em_size--;
                }
            }
            std::cout << "-----------------------------------" << std::endl;
            std::cout << p;
            std::cout << "-----------------------------------" << std::endl;
        }
    }
    else print_not_created();
}

ArrayDeque::~ArrayDeque()
{
    delete [] content;
}


