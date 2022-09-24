#include <iostream>

//Node constructor
template<class T> NodeList <T> :: Node :: Node(T value) {

    this->value = new T;
    *(this->value) = value;
}

//NodeList Constructors / Destructors
template <class T> NodeList <T> :: NodeList() {

    this->head = nullptr;
    this->tail = nullptr;
    _size = 0;
}

template <class T> NodeList <T> :: ~NodeList() {

    this->clear();
}

//Returns the list size
template<class T> size_t NodeList <T> :: size() {

    return _size;
}

//Checks whether the list is empty
template<class T> bool NodeList<T>::isEmpty() {

    return (bool) !_size;
}

//Deletes all the elements
template<class T> void NodeList<T>::clear() {

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

}

template<class T> void NodeList<T>::eraseNode(NodeList::Node* node) {

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
}

template<class T> void NodeList<T>::pushFont(T value) {

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

template<class T> void NodeList<T>::pushBack(T value) {

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

template<class T> void NodeList<T>::popFront() {

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
}

template<class T> void NodeList<T>::popBack() {

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
}
