int SkipList::generate_random_int(int max_value, int min_value)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min_value, max_value);
    return dist(gen);
}

bool SkipList::flip_a_coin()
{
    return (bool) generate_random_int(1,0);
}


SkipList::Node::Node(int value)
{
    this->value = value;
}

SkipList::SkipList()
{
    Sentinel = new Node(INT_MIN);
    Sentinel->next.push_back(nullptr); // layer 0
    Sentinel->next.push_back(nullptr); // layer 1
    layer_number = 1;
    cur_size = 0;
}

void SkipList::build()
{
    {
        Node* p = Sentinel;
        Node* n;
        while(p!= nullptr)
        {
            n = p->next[0];
            p->next.resize(0);
            p->next.push_back(n);
            p=p->next[0];
        }
    }

    for(int i = 1; i <= layer_number; i++) Sentinel->next.push_back(nullptr);

    for(int li = 1; li <= layer_number; li++)
    {
        Node* ptr = Sentinel->next[li-1];
        Node* prev = Sentinel;

        while(ptr != nullptr)
        {
            if(flip_a_coin())
            {
                ptr->next.push_back(nullptr);
                prev->next[li] = ptr;
                prev = ptr;
            }
            ptr = ptr->next[li-1];
        }
    }
}

SkipList::Node* SkipList::findNode(int key)
{

    Node* ptr = Sentinel;

    for(int li = layer_number; li>=0; li--)
    {
        while(ptr->next[li]) // and li < ptr->next.size()
        {
            if(ptr->next[li]->value == key) return ptr->next[li];
            else if(ptr->next[li]->value > key) break;
            ptr = ptr->next[li];
        }
    }

    return nullptr;
}

std::vector<SkipList::Node*> SkipList::findPath(int key) // finds predecessors
{
    std::vector<SkipList::Node*> path(layer_number+1, nullptr);
    Node* ptr = Sentinel;

    for(int li = layer_number; li>=0; li--)
    {
        while(ptr->next[li]) // and li < ptr->next.size()
        {
            if(ptr->next[li]->value >= key)
                break;
            ptr = ptr->next[li];
        }
        path[li] = ptr;
    }

    return path;
}

void SkipList::insert(int value)
{
    cur_size++;
    if(cur_size > 2)
        if(layer_number != (int)ceil(log2(cur_size)))
        {
            layer_number++;
            this->build();
        }

    Node* new_node = new Node(value);
    std::vector <Node*> path = findPath(value);
    short new_height = 0;
    while (new_height < layer_number and flip_a_coin()) new_height++;
    new_node->next = std::vector<Node*> (new_height+1, Sentinel);

    /*
    std::cout << "Sentinel :" << Sentinel << "; \t";
    for(auto x : path)
        std::cout << x << ' ';
    std::cout << std::endl;
    */

    for(short li = 0; li <= new_height; li++)
    {
        new_node->next[li] = path[li]->next[li];
        path[li]->next[li] = new_node;
    }

}

void SkipList::print()
{
    Node* ptr = Sentinel->next[0];
    std::cout << "List :" << std::endl;
    while (ptr!= nullptr)
    {
        std::cout << ptr->value << ' ';
        ptr=ptr->next[0];
    }
    std::cout << std::endl;
}

SkipList::~SkipList()
{
    Node* node = Sentinel;
    while(node->next[0]!=nullptr)
    {
        Node* tmp = node;
        node = node->next[0];
        delete tmp;
    }
    delete node;
}
