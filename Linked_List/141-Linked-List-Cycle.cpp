// LeetCode 141 - Linked List Cycle
// Difficulty: Easy
// Topic: Linked List, Two Pointers
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
//
// Problem:
// Given the head of a linked list, determine if the linked
// list contains a cycle.
//
// Approach Explanation:
// 1. Initialize two pointers, slow and fast, at the head.
// 2. Move slow one step at a time.
// 3. Move fast two steps at a time.
// 4. If the pointers ever meet, a cycle exists.
// 5. If fast reaches the end of the list, there is no cycle.
//
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
       return false;
    }
};
