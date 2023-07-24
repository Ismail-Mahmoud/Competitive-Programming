// https://leetcode.com/problems/lru-cache/

class LRUCache {
private:
    class Node {
    public:
        int key, val;
        Node *prev, *next;
        Node(): key(-1), val(-1), prev(nullptr), next(nullptr) {}
        Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) {
            return -1;
        }
        int val = it->second->val;
        // put(key, val);
        deleteNode(it->second);
        addHead(key, val);
        return val;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()) {     // delete then add as the head
            deleteNode(it->second);
        }
        else if(cache.size() == capacity) {
            deleteNode(tail);
        }
        addHead(key, value);
    }

    void addHead(int key, int val) {
        Node* node = new Node(key, val);
        if(!head) {     // empty
            head = tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
        }
        cache[key] = head = node;
    }

    void deleteNode(Node* node) {
        if(node != head && node != tail) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            cache.erase(node->key);
            return;
        }
        if(node == head) {
            head = node->next;
        }
        if(node == tail) {
            tail = node->prev;
        }
        cache.erase(node->key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */