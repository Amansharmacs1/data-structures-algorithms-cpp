// LeetCode 146 - LRU Cache
// Difficulty: Medium
// Topic: Linked List, Hash Table, Design
// Approach: Doubly Linked List + Hash Map
//
// Problem:
// Design a data structure that supports the following operations
// in O(1) time:
// - get(key): Return the value if the key exists, otherwise -1.
// - put(key, value): Insert or update the key. If the cache
//   exceeds its capacity, remove the Least Recently Used (LRU) item.
//
// Approach Explanation:
// 1. Use a doubly linked list to maintain the usage order.
//    - Most Recently Used (MRU) node is placed right after the head.
//    - Least Recently Used (LRU) node is placed right before the tail.
// 2. Use a hash map to map each key to its corresponding node
//    in the linked list.
// 3. For get(key):
//    - If the key exists, move its node to the front
//      (most recently used) and return its value.
//    - Otherwise, return -1.
// 4. For put(key, value):
//    - If the key already exists, remove the old node.
//    - If the cache is full, remove the LRU node
//      (node before the tail).
//    - Insert the new node at the front and update the hash map.
//
// Time Complexity:
// Get : O(1)
// Put : O(1)
//
// Space Complexity: O(capacity)

class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int k,int v){
            key=k;
            val=v;
            prev=next=NULL;
        }

    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    unordered_map<int,Node*> m;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext=head->next;

        head->next=newNode;
        oldNext->prev=newNode;

        newNode->next=oldNext;
        newNode->prev=head;

    }

    void delNode(Node* oldNode){
        Node* oldPrev=oldNode->prev;
        Node* oldNext=oldNode->next;

        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;
    }

    LRUCache(int capacity){
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }


    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansNode=m[key];
        int ans=ansNode->val;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key]=ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* oldNode=m[key];
            delNode(oldNode);
            m.erase(key);
        }
        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode=new Node(key,value);
        addNode(newNode);
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
