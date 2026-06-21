// LeetCode 707 - Design Linked List
// Difficulty: Medium
// Topic: Linked List, Design
// Approach: Singly Linked List with Dummy Head
//
// Problem:
// Design a linked list that supports the following operations:
// - Get the value at an index
// - Add a node at the head
// - Add a node at the tail
// - Add a node at a specific index
// - Delete a node at a specific index
//
// Approach Explanation:
// 1. Use a dummy head node to simplify insertion and deletion.
// 2. Maintain the current size of the linked list.
// 3. Traverse to the required position for each operation.
// 4. Update pointers to insert or remove nodes.
// 5. Return -1 for invalid indices in the get operation.
//
// Time Complexity:
// - get(): O(n)
// - addAtHead(): O(1)
// - addAtTail(): O(n)
// - addAtIndex(): O(n)
// - deleteAtIndex(): O(n)
//
// Space Complexity: O(n)

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };
    
    Node* dummy;  // dummy head
    int size;

public:
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;
        
        Node* curr = dummy->next;
        for(int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;
        
        Node* prev = dummy;
        for(int i = 0; i < index; i++) {
            prev = prev->next;
        }
        
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;
        
        Node* prev = dummy;
        for(int i = 0; i < index; i++) {
            prev = prev->next;
        }
        
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        
        size--;
    }
};
