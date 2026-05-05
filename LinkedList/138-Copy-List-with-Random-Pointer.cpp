// LeetCode 138 - Copy List with Random Pointer
// Difficulty: Medium
// Topic: Linked List, Hashing
// Approach: Hash Map (Old → New node mapping)
//
// Problem:
// Create a deep copy of a linked list where each node has:
// - next pointer
// - random pointer (can point anywhere or NULL)
//
// Approach Explanation:
// 1. Traverse list and create copy nodes
// 2. Store mapping: original node → copied node
// 3. Traverse again to assign random pointers using map
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*, Node*> m;

        Node* newHead = new Node(head->val);
        m[head] = newHead;

        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        // create nodes and next pointers
        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp] = copyNode;
            newTemp->next = copyNode;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // assign random pointers
        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != NULL){
            if(oldTemp->random != NULL)
                newTemp->random = m[oldTemp->random];
            else
                newTemp->random = NULL;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};
