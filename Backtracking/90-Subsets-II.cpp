// LeetCode 90 - Subsets II
// Difficulty: Medium
// Topic: Backtracking
// Approach: Recursion with Duplicate Skipping
//
// Problem:
// Given an array nums that may contain duplicates,
// return all possible subsets without duplicates.
//
// Approach Explanation:
// 1. Sort the array to group duplicates
// 2. At each step:
//    - Include current element
//    - Exclude current element and skip duplicates
//
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:
    void getAllSubsets(vector<int> &nums, vector<int> &ans, int i,
                       vector<vector<int>> &allSubsets){

        if(i == nums.size()){
            allSubsets.push_back(ans);
            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        // exclude
        ans.pop_back();

        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[i]) idx++;

        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // ✅ correct place

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
