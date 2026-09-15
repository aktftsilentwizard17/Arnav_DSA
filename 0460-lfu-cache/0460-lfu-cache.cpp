class LFUCache { //in addition to node map, needs a frequency map to track frequencies
private:
    struct Node {
        int key, val, freq;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
    };

    // Helper class for a Doubly Linked List with Sentinel Head & Tail
    struct List {
        Node* head;
        Node* tail;
        int size;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addNode(Node* node) {
            Node* oldNext = head->next;
            head->next = node;
            node->prev = head;
            node->next = oldNext;
            oldNext->prev = node;
            size++;
        }

        void delNode(Node* node) {
            Node* oldPrev = node->prev;
            Node* oldNext = node->next;
            oldPrev->next = oldNext;
            oldNext->prev = oldPrev;
            size--;
        }

        Node* removeLRU() {
            if (size == 0) return nullptr;
            Node* lru = tail->prev;
            delNode(lru);
            return lru;
        }
    };

    int capacity;
    int minFreq;
    unordered_map<int, Node*> keyTable;
    unordered_map<int, List*> freqTable;

    // Helper function to update frequency of an existing node
    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqTable[oldFreq]->delNode(node);

        // If the list of the minimum frequency becomes empty, increment minFreq
        if (freqTable[oldFreq]->size == 0 && minFreq == oldFreq) {
            minFreq++;
        }

        node->freq++;
        if (freqTable.find(node->freq) == freqTable.end()) {
            freqTable[node->freq] = new List();
        }
        freqTable[node->freq]->addNode(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    int get(int key) {
        if (keyTable.find(key) == keyTable.end()) {
            return -1;
        }
        Node* node = keyTable[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        // If key exists, update value and bump frequency
        if (keyTable.find(key) != keyTable.end()) {
            Node* node = keyTable[key];
            node->val = value;
            updateFreq(node);
            return;
        }

        // If at full capacity, evict least frequently used item
        if (keyTable.size() == capacity) {
            List* minList = freqTable[minFreq];
            Node* lru = minList->removeLRU();
            keyTable.erase(lru->key);
            delete lru;
        }

        // Insert new node (frequency starts at 1)
        Node* newNode = new Node(key, value);
        keyTable[key] = newNode;
        minFreq = 1;

        if (freqTable.find(1) == freqTable.end()) {
            freqTable[1] = new List();
        }
        freqTable[1]->addNode(newNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */