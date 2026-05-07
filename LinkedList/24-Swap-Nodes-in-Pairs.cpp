// LeetCode 24 - Swap Nodes in Pairs
// Difficulty: Medium
// Topic: Linked List, Pointer Manipulation
// Approach: Iterative pointer swapping in pairs
//
// Problem:
// Given a linked list, swap every two adjacent nodes and return its head.
// You must not change the values in the nodes, only nodes themselves.
//
// Approach Explanation:
// - Traverse the list in pairs (first and second node).
// - Store next pair start (third node).
// - Reverse links between first and second node.
// - Connect previous pair to current swapped pair.
// - Update pointers and continue.
//
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while (first != NULL && sec != NULL) {

            ListNode* third = sec->next;

            // swap
            sec->next = first;
            first->next = third;

            // connect previous pair
            if (prev != NULL) {
                prev->next = sec;
            } 
            else {
                head = sec;
            }

            // update pointers
            prev = first;
            first = third;

            if (third != NULL) {
                sec = third->next;
            } 
            else {
                sec = NULL;
            }
        }

        return head;
    }
};
