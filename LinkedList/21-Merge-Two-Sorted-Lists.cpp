// LeetCode 21 - Merge Two Sorted Lists
// Difficulty: Easy
// Topic: Linked List
// Approach: Recursion
//
// Problem:
// Merge two sorted linked lists and return it as a sorted list.
//
// Approach Explanation:
// Compare the current nodes of both lists:
// - Smaller node becomes part of result
// - Recursively merge the remaining list
//
// Time Complexity: O(n + m)
// Space Complexity: O(n + m) (recursion stack)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        if(head1->val < head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
};
