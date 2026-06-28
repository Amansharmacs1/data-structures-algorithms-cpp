// LeetCode 540 - Single Element in a Sorted Array
// Difficulty: Medium
// Topic: Binary Search, Bit Manipulation, Array
// Approach: XOR
//
// Problem:
// Given a sorted array where every element appears exactly twice
// except for one element that appears only once, find that single element.
//
// Approach Explanation:
// 1. Initialize a variable ans = 0.
// 2. Traverse the array and XOR every element with ans.
// 3. Duplicate elements cancel each other out (x ^ x = 0).
// 4. The remaining value is the element that appears only once.
//
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
  
        int ans=0;
        for(int val : arr){
            ans=ans^val;
        }
       return ans;

    }
};
