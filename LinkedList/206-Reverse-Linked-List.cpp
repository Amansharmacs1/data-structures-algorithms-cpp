// LeetCode 206 - Reverse Linked List
// Difficulty: Easy
// Topic: Linked List
// Approach: Iterative (Three Pointers)
//
// Problem:
// Reverse a singly linked list and return the new head.
//
// Approach Explanation:
// Use three pointers:
// - prev → previous node
// - curr → current node
// - next → store next node temporarily
//
// Steps:
// 1. Save next node
// 2. Reverse current node's pointer
// 3. Move prev and curr forward
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;   // store next
            curr->next = prev;   // reverse link

            prev = curr;         // move prev
            curr = next;         // move curr
        }

        return prev;
    }
};
