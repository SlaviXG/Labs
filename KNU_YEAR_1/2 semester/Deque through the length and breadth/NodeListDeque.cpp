#include "NodeListDeque.h"

void NodeListDeque::print_not_created()
{
    std::cerr << "Deque is not created." << std::endl;
}

void NodeListDeque::print_is_empty()
{
    std::cerr << "Deque is empty." << std::endl;
}

void NodeListDeque::create_empty(bool logging)
{
    if(created) this->clear(false);
    _size = 0;
    created = true;
    if(logging) std::cout << "Successfully created." << std::endl;
}

size_t NodeListDeque::size()
{
    if(created) return _size;
    print_not_created();
    return 0;
}

Point NodeListDeque::front()
{
    if(created)
    {
        if(_size) return *(head->point);
        else print_is_empty();
    }
    else print_not_created();

    return Point();
}

Point NodeListDeque::back()
{
    if(created)
    {
        if (_size) return *(tail->point);
        else print_is_empty();
    }
    else print_not_created();

    return Point();
}

void NodeListDeque::append_left(Point point)
{
    if(created)
    {
        Node* node = new Node (point);

        if(head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }

        _size++;
    }
    else print_not_created();
}

void  NodeListDeque::append(Point point)
{
    if(created)
    {
        Node* node = new Node (point);

        if(tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        _size++;
    }
    else print_not_created();
}

bool NodeListDeque::is_empty()
{
    if(created) return (bool) !_size;
    print_not_created();
    return true;
}

void NodeListDeque::clear(bool logging)
{
    if(created)
    {
        Node* p = head;
        Node* t;

        while(p!= nullptr)
        {
            t = p;
            p = p->next;
            delete t->point;
            delete t;
        }

        head = nullptr;
        tail = nullptr;

        _size = 0;

        if(logging) std::cout << "Cleared." << std::endl;
    }
    else print_not_created();
}

Point NodeListDeque::pop_left(bool logging)
{
    if(created)
    {
        if(_size)
        {
            Point p = *(head->point);

            delete head->point;
            Node* t_p = head;
            head = head->next;
            delete t_p;
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

Point NodeListDeque::pop(bool logging)
{
    if(created)
    {
        if(_size)
        {
            Point p = *(tail->point);

            delete tail->point;
            Node* t_p = tail;
            tail = tail->prev;
            delete t_p;
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

void NodeListDeque::print()
{
    if(created)
    {
        std::cout << "Points in the amount of " << _size << std::endl;
        Node* p = head;
        while (p!=nullptr)
        {
            std::cout << "-----------------------------------" << std::endl;
            std::cout << *(p->point);
            std::cout << "-----------------------------------" << std::endl;
            p=p->next;
        }
    }
    else print_not_created();
}

NodeListDeque::~NodeListDeque()
{
    Node* p = head;
    Node* t;

    while(p!=nullptr)
    {
        t = p;
        p = p->next;
        delete t->point;
        delete t;
    }

    head = nullptr;
    tail = nullptr;

    created = false;
}