// LeetCode 53 - Maximum Subarray
// Difficulty: Medium
// Topic: Arrays, Dynamic Programming
// Approach: Kadane's Algorithm
//
// Problem:
// Given an integer array nums, find the subarray with the largest sum and return its sum.
//
// Approach Explanation:
// We use Kadane’s Algorithm.
// At each index, we decide whether to:
// 1. Extend the previous subarray (curr + nums[i])
// 2. Start a new subarray from current element (nums[i])
//
// We keep updating:
// curr = maximum subarray sum ending at current index
// maxx = overall maximum subarray sum
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int maxx = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            curr = max(curr + nums[i], nums[i]);
            maxx = max(maxx, curr);
        }
        
        return maxx;
    }
};
