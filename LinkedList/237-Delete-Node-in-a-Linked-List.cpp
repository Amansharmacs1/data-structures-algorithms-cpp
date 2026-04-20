// LeetCode 237 - Delete Node in a Linked List
// Difficulty: Medium
// Topic: Linked List
// Approach: Copy Next Node Data
//
// Problem:
// You are given a node (not the head) in a singly linked list.
// Delete that node without access to the head.
//
// Approach Explanation:
// Since we don't have access to the previous node,
// we copy the value of the next node into the current node,
// then delete the next node.
//
// Steps:
// 1. Copy next node's value → node->val = node->next->val
// 2. Skip next node → node->next = node->next->next
// 3. Delete the next node
//
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL){
            return;
        }

        ListNode* newNode = node->next;
        node->val = newNode->val;
        node->next = newNode->next;

        delete newNode;
    }
};
