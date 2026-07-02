// LeetCode 234 - Palindrome Linked List
// Difficulty: Easy
// Topic: Linked List, Two Pointers
// Approach: Find Middle + Reverse Second Half
//
// Problem:
// Given the head of a singly linked list, determine
// whether it is a palindrome.
//
// Approach Explanation:
// 1. Use slow and fast pointers to find the middle of the list.
// 2. Reverse the second half of the linked list.
// 3. Compare the first half and the reversed second half
//    node by node.
// 4. If all corresponding nodes are equal, the list is
//    a palindrome; otherwise, it is not.
//
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

      
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        ListNode* second = reverse(slow->next);

       
        ListNode* first = head;
        while (second) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};
