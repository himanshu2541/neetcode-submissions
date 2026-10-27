class LRUCache {

private:
    struct Node{
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }

    };

    unordered_map<int, Node*> mp;
    int capacity;

    Node *head;
    Node *tail;

    // remove a node from its current position
    void removeNode(Node *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // insert a node immediately after head
    void insertFront(Node *node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // mark an existing node as most recently used
    void moveToFront(Node *node){
        removeNode(node);
        insertFront(node);
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node *node = mp[key];
        moveToFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // if key already exists, update
        if(mp.find(key) != mp.end()){
            Node *node = mp[key];
            node->val = value;
            moveToFront(node);
            return;
        }
        // if cache is full, remove LRU
        if(mp.size() == capacity){
            Node *lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node *node = new Node(key, value);
        insertFront(node);
        mp[key] = node;
    }
};
