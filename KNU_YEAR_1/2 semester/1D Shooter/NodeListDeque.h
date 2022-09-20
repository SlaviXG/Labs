#ifndef INC_1D_SHOOTER_NODELISTDEQUE_H
#define INC_1D_SHOOTER_NODELISTDEQUE_H

#include <iostream>

template <class T> struct NodeListDeque
{
private:
    struct Node
    {
        T* value;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node (T value)
        {
            this->value = new T;
            *(this->value) = value;
        }
    };

    bool created;
    size_t _size;

    void print_not_created()
    {
        std::cerr << "Deque is not created." << std::endl;
    }
    void print_is_empty()
    {
        std::cerr << "Deque is empty." << std::endl;
    }
public:
    Node* head = nullptr;
    Node* tail = nullptr;

    NodeListDeque()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->create_empty(false);
    }
    void create_empty(bool logging = false)
    {
        if(created) this->clear(false);
        _size = 0;
        created = true;
        if(logging) std::cout << "Deque is successfully created." << std::endl;
    }
    size_t size()
    {
        if(created) return _size;
        print_not_created();
        return 0;
    }
    T front()
    {
        if(created)
        {
            if(_size) return *(head->value);
            else print_is_empty();
        }
        else print_not_created();
        return T();
    }
    T back()
    {
        if(created)
        {
            if (_size) return *(tail->value);
            else print_is_empty();
        }
        else print_not_created();
        return T();
    }
    void push_font(T value)
    {
        if(created)
        {
            Node* node = new Node (value);

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
    void push_back(T value)
    {
        if(created)
        {
            Node* node = new Node (value);

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
    void pop_front(bool logging = false)
    {
        if(created)
        {
            if(_size)
            {
                T p = *(head->value);

                delete head->value;
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
    }
    void pop_back(bool logging = false)
    {
        if(created)
        {
            if(_size)
            {
                T p = *(tail->value);

                delete tail->value;
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
    }
    void erase (Node* node, bool logging = false)
    {
        if(created)
        {
            if(_size)
            {
                if(node == head) //Deleting from the beginning
                {
                    head = head->next;
                    if(head == nullptr) //(if the size was 1)
                    {
                        head = tail = nullptr;
                    }
                    else //if the size was not 1
                    {
                        head->prev = nullptr;
                    }
                }
                else
                {
                    if (node == tail)
                    {
                        tail = node->prev;
                        tail->next = nullptr;
                    }
                    else
                    {
                        Node *prv = node->prev;
                        Node *nxt = node->next;

                        prv->next = nxt;
                        nxt->prev = prv;
                    }

                    delete node->value;
                    delete node;
                }
                _size--;
            }
            else
            {
                if(logging) print_is_empty();
            }
        }
        else
            print_not_created();
    }
    bool is_empty()
    {
        if(created) return (bool) !_size;
        print_not_created();
        return true;
    }
    void clear(bool logging = false)
    {
        if(created)
        {
            Node* p = head;
            Node* t;

            while(p!= nullptr)
            {
                t = p;
                p = p->next;
                delete t->value;
                delete t;
            }

            head = nullptr;
            tail = nullptr;

            _size = 0;

            if(logging) std::cout << "Cleared." << std::endl;
        }
        else print_not_created();
    }
    void print()
    {
        if(created)
        {
            Node* p = head;
            while (p!=nullptr)
            {
                std::cout << *(p->value) << std::endl;
                p=p->next;
            }
        }
        else print_not_created();
    }
    ~NodeListDeque()
    {
        Node* p = head;
        Node* t;

        while(p!=nullptr)
        {
            t = p;
            p = p->next;
            delete t->value;
            delete t;
        }

        head = nullptr;
        tail = nullptr;

        created = false;
    }
};

#endif //INC_1D_SHOOTER_NODELISTDEQUE_H
