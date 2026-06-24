// LeetCode 876 - Middle of the Linked List
// Difficulty: Easy
// Topic: Linked List, Two Pointers
// Approach: Slow and Fast Pointers
//
// Problem:
// Given the head of a singly linked list, return the middle node.
// If there are two middle nodes, return the second middle node.
//
// Approach Explanation:
// 1. Initialize two pointers: slow and fast at the head.
// 2. Move slow by one node and fast by two nodes.
// 3. When fast reaches the end of the list,
//    slow will be at the middle.
// 4. Return the slow pointer.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        }
        return slow;

    }
};
