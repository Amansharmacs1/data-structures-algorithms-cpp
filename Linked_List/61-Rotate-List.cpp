// LeetCode 61 - Rotate List
// Difficulty: Medium
// Topic: Linked List
// Approach: Rotate One Position Repeatedly
//
// Problem:
// Given the head of a linked list, rotate the list to the
// right by k places.
//
// Approach Explanation:
// 1. Compute the length of the linked list.
// 2. Reduce unnecessary rotations by computing k %= length.
// 3. Rotate the list one position to the right, k times.
// 4. In each rotation:
//    - Find the second last node.
//    - Make the last node the new head.
//    - Update the links accordingly.
// 5. Return the new head after all rotations.
//
// Time Complexity: O(n × k)
// Space Complexity: O(1)


class Solution {
public:
    ListNode* rotateOnce(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* temp=head;
        while(temp->next!=NULL && temp->next->next!=NULL){
            temp=temp->next;
        }
        ListNode* last=temp->next;
        temp->next=NULL;
        last->next=head;
        head=last;
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL ){
            temp=temp->next;
            len++;
        }
        k=k%len;

        int cnt=0;
        while(cnt<k){
            head=rotateOnce(head);
            cnt++;
        }
        return head;
    }
};
