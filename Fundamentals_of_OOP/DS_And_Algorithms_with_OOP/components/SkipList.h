#include <iostream>
#include <vector>
#include <random>

template <typename T> class SkipList{
private:
    struct Node {
        // array of pointers :
        std::vector <Node*> next;
        // value :
        T value;
        // Node constructor
        Node(T value);
    };

    Node* Sentinel = nullptr;
    int cur_size;
    int layer_number;

    void build();
    std::vector <Node*> findPath (T key);
    static int generate_random_int(int max_value, int min_value = 1);
    static bool flip_a_coin();

public:
    explicit SkipList(T minObject);
    ~SkipList();
    Node* findNode (T key);
    void insert (T value);
    void print();
};

#include "SkipList.hpp"