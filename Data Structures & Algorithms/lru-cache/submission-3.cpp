class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node *prev, *next;
        Node(int k, int v, Node *p, Node *n) : key(k), value(v), prev(p), next(n) {}
    };

    unordered_map<int, Node*> keys;
    Node *head, *tail;
    int key_nums;
    int capacity;

public:
    LRUCache(int capacity) {
        head = new Node(-1, -1, nullptr, nullptr);
        tail = new Node(-1, -1, nullptr, nullptr);
        key_nums = 0;
        this->capacity = capacity;

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (keys.count(key)) {
            Node *key_node = keys[key];
            removeNode(key_node);
            addNodeToTail(key_node);

            return keys[key]->value;
        } else return -1;
    }
    
    void put(int key, int value) {
        if (keys.count(key)) {
            Node *key_node = keys[key];
            removeNode(key_node);
            addNodeToTail(key_node);
            key_node->value = value;
            
        } else {
            Node *key_node = new Node(key, value, nullptr, nullptr);
            keys[key] = key_node;
            addNodeToTail(key_node);
            key_nums++;
        }

        if (key_nums > capacity) {
            Node *evict_node = head->next;
            keys.erase(evict_node->key);
            removeNode(evict_node);
            delete evict_node;
            key_nums--;
        }
    }

    void addNodeToTail(Node *node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};
