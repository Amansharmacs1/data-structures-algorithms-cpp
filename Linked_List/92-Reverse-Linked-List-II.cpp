// LeetCode 92 - Reverse Linked List II
// Difficulty: Medium
// Topic: Linked List
// Approach: Reverse Sublist In-Place
//
// Problem:
// Reverse a linked list from position left to right
// (1-indexed) and return the modified list.
//
// Approach Explanation:
// 1. Traverse to the node at position 'left' while
//    keeping track of its previous node.
// 2. Reverse exactly (right - left + 1) nodes.
// 3. Connect the node before the reversed part to
//    the new head of the reversed sublist.
// 4. Connect the tail of the reversed sublist to
//    the remaining list.
// 5. Return the updated head.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* reversefunc(ListNode* head,int len){
        ListNode * prev=NULL;
        ListNode * curr=head;
        ListNode * next=NULL;
        int cnt=0;
        while(curr!=NULL && cnt<len){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right){
        if(!head || left==right) return head;

        ListNode* temp=head;
        ListNode* prev=NULL;
        int cnt=1;
        //left
        while(cnt<left){
            prev=temp;
            temp=temp->next;

            cnt++;
        }

        ListNode* tail=temp;

        //right
        cnt=0;
        ListNode* Next=temp;
        while(cnt<(right-left+1)){
            Next=Next->next;
            cnt++;
        }

        ListNode* newHead=reversefunc(temp,right-left+1);
        if(prev!=NULL){
            prev->next=newHead;
        }
        else head=newHead;

        tail->next=Next;
        return head;
    }
};
