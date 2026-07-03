// LeetCode 2 - Add Two Numbers
// Difficulty: Medium
// Topic: Linked List
// Approach: Digit-by-Digit Addition with Carry
//
// Problem:
// Given two non-empty linked lists representing two non-negative
// integers in reverse order, add the two numbers and return the
// sum as a linked list.
//
// Approach Explanation:
// 1. Create a dummy node to build the answer list.
// 2. Traverse both linked lists simultaneously.
// 3. At each step, add the current digits and the carry.
// 4. Create a new node with (sum % 10).
// 5. Update carry as (sum / 10).
// 6. Continue until both lists and the carry are exhausted.
//
// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m)) (for the output list)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }
};
