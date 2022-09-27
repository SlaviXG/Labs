#include <iostream>
#include <vector>
#include <random>

class SkipList
{
    private :
    static int generate_random_int(int max_value, int min_value = 1);
    static bool flip_a_coin();
    int cur_size;
    int layer_number;
    struct Node
    {
        // array of pointers :
        std::vector <Node*> next;
        // value :
        int value;
        Node(int value);
    };
    Node* Sentinel = nullptr;
    void build();
    std::vector <Node*> findPath (int key);
    public:
    SkipList(); // LEGO!!!
    Node* findNode (int key);
    void insert (int value);
    void print();
    ~SkipList();
};

#include "SkipList.hpp"