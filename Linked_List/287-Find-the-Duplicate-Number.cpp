// LeetCode 287 - Find the Duplicate Number
// Difficulty: Medium
// Topic: Linked List, Two Pointers
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
//
// Problem:
// Given an array containing n + 1 integers where each integer
// is in the range [1, n], find the duplicate number without
// modifying the array and using only constant extra space.
//
// Approach Explanation:
// 1. Treat the array as a linked list where each value points
//    to the next index.
// 2. Use slow and fast pointers to detect the cycle.
// 3. Once they meet, move one pointer to the beginning.
// 4. Move both pointers one step at a time.
// 5. The point where they meet again is the duplicate number.
//
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int findDuplicate(vector<int>& num) {
        int slow=num[0];
        int fast=num[0];
        
        slow=num[slow];
        fast=num[num[fast]];
        while(1){
            if(slow==fast){
                slow=num[0];
                break;  
            }
            slow=num[slow];
            fast=num[num[fast]];
        }
        while(1){
            if(slow==fast){
                break;
            }
            slow=num[slow];
            fast=num[fast];
        }
        return slow;
    }
};
