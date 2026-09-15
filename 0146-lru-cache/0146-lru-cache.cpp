class LRUCache {
public:
    class Node{
    public:
        int key,val;
        Node *prev;
        Node *next;

        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> m;

    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void delNode (Node* oldNode) {
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        // get that node at the first node
        if(m.find(key)==m.end()){
            return -1;
        }
        Node *ansnode = m[key];
        int ans = ansnode->val;

        // Simply move node to head (no need to erase/re-insert in map)
        delNode(ansnode);
        addNode(ansnode);
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){ //corner case
            Node* oldnode = m[key];
            delNode(oldnode);
            m.erase(key);
            delete oldnode; // Fixed memory leak: free old node
        }
        if(m.size()==limit){ //corner case
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
            delete lru; // Fixed memory leak: free evicted node
        }
        Node* newnode = new Node(key,value);
        addNode(newnode);
        m[key]=newnode;
    }
};