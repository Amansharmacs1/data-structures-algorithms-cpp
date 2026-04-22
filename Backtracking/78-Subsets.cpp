// LeetCode 78 - Subsets
// Difficulty: Medium
// Topic: Backtracking
// Approach: Recursion (Include / Exclude)
//
// Problem:
// Given an integer array nums of unique elements,
// return all possible subsets (the power set).
//
// Approach Explanation:
// At each index, we have 2 choices:
// 1. Include the current element
// 2. Exclude the current element
//
// This forms a recursion tree of size 2^n.
//
// Base case:
// When we reach end → store current subset
//
// Time Complexity: O(2^n * n)
// Space Complexity: O(n) (recursion stack)

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
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
