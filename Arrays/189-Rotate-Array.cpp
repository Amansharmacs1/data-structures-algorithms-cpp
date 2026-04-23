// LeetCode 189 - Rotate Array
// Difficulty: Medium
// Topic: Arrays
// Approach: Reversal Algorithm
//
// Problem:
// Given an array, rotate the array to the right by k steps.
//
// Approach Explanation:
// We use the reversal technique:
// 1. Reverse entire array
// 2. Reverse first k elements
// 3. Reverse remaining elements
//
// Example:
// nums = [1,2,3,4,5,6,7], k = 3
// → [5,6,7,1,2,3,4]
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void reverseArr(vector<int> &nums, int a, int b){
        for(int i = a, j = b; i < j; i++, j--){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverseArr(nums, 0, n - 1);
        reverseArr(nums, 0, k - 1);
        reverseArr(nums, k, n - 1);
    }
};
