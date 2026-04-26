// LeetCode 26 - Remove Duplicates from Sorted Array
// Difficulty: Easy
// Topic: Arrays, Two Pointers
// Approach: Two Pointer Technique
//
// Problem:
// Given a sorted array nums, remove duplicates in-place
// such that each element appears only once.
// Return the number of unique elements (k).
//
// Approach Explanation:
// We use two pointers:
// - i → traverses array
// - k → position to place next unique element
//
// If nums[i] != nums[i-1]:
// → place nums[i] at nums[k] and increment k
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int k = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1]){
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
