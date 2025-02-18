struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
    Node(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    Node(int x, int y, Node* next, Node* prev)
        : key(x), val(y), next(next), prev(prev) {}
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node();
        right = new Node();
        left->next = right;
        right->prev = left;
    }

    // right
    void insert(Node* node) {
        node->next = right;
        node->prev = right->prev;
        right->prev->next = node;
        right->prev = node;
    }

    // left
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        insert(node);
        if (cache.size() > cap) {
            Node* lru = left->next;
            // left->next = node->next;
            // node->next->prev = left;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */