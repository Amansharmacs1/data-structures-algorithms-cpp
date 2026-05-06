// LeetCode 430 - Flatten a Multilevel Doubly Linked List
// Difficulty: Medium
// Topic: Linked List, Recursion, DFS
// Approach: Recursive DFS with pointer relinking
//
// Problem:
// Given a multilevel doubly linked list, flatten it so that all nodes appear in a single-level,
// doubly linked list in the same order as a depth-first traversal.
//
// Approach Explanation:
// - Traverse the list node by node.
// - If a node has a child, recursively flatten the child list.
// - Insert the flattened child list between current node and next node.
// - Properly maintain prev and next pointers.
// - Ensure child pointer is set to NULL after merging.
//
// Time Complexity: O(N)
// Space Complexity: O(N) (recursion stack)

class Solution {
public:

    Node* flatten(Node* head) {
        if (!head) return head;
        flattenDFS(head);
        return head;
    }

    // returns tail of flattened list
    Node* flattenDFS(Node* head) {
        Node* curr = head;
        Node* last = head;

        while (curr) {
            Node* next = curr->next;

            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                // connect current node to child
                curr->next = childHead;
                childHead->prev = curr;

                curr->child = NULL;

                // connect child tail to next
                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                last = childTail;
                curr = childTail;
            }
            else {
                last = curr;
            }

            curr = curr->next;
        }

        return last;
    }
};
