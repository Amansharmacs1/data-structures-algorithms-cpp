// LeetCode 283 - Move Zeroes
// Difficulty: Easy
// Topic: Arrays, Two Pointers
// Approach: Overwrite + Fill Zeroes
//
// Problem:
// Given an integer array nums, move all 0's to the end
// while maintaining the relative order of non-zero elements.
//
// Approach Explanation:
// 1. Use pointer k to place non-zero elements
// 2. Traverse array and copy non-zero elements to front
// 3. Fill remaining positions with 0
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                nums[k++] = nums[i];
            }
        }

        while(k < n){
            nums[k++] = 0;
        }
    }
};
