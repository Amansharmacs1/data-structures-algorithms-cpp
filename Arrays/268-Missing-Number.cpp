// LeetCode 268 - Missing Number
// Difficulty: Easy
// Topic: Arrays
// Approach: Sorting
//
// Problem:
// Given an array containing n distinct numbers in range [0, n],
// return the only number missing from the array.
//
// Approach Explanation:
// 1. Sort the array
// 2. Check:
//    - If first element is not 0 → missing is 0
//    - Otherwise find where nums[i] + 1 != nums[i+1]
//
// Time Complexity: O(n log n)
// Space Complexity: O(1) (ignoring sort space)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        if(nums[0] != 0) return 0;

        for(int i = 0; i < n - 1; i++){
            if(nums[i] + 1 != nums[i + 1]){
                return nums[i] + 1;
            }
        }

        return n;
    }
};
