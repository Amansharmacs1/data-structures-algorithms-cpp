// LeetCode 142 - Linked List Cycle II
// Difficulty: Medium
// Topic: Linked List
// Approach: Floyd’s Cycle Detection (Tortoise & Hare)
//
// Problem:
// Given a linked list, return the node where the cycle begins.
// If there is no cycle, return NULL.
//
// Approach Explanation:
// 1. Use two pointers (slow & fast)
//    - slow moves 1 step
//    - fast moves 2 steps
//
// 2. If they meet → cycle exists
//
// 3. Move slow to head, keep fast at meeting point
//
// 4. Move both one step at a time
//    → they meet at cycle start
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }

        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
