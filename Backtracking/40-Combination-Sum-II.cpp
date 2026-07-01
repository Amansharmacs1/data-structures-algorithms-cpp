// LeetCode 40 - Combination Sum II
// Difficulty: Medium
// Topic: Backtracking, Recursion, Sorting
// Approach: Backtracking with Sorting & Duplicate Skipping
//
// Problem:
// Given a collection of candidate numbers and a target,
// find all unique combinations where the chosen numbers
// sum to the target. Each number may be used at most once.
//
// Approach Explanation:
// 1. Sort the array to group duplicate elements together.
// 2. Start building combinations using backtracking.
// 3. At each step, choose the current element and reduce
//    the remaining target.
// 4. Skip duplicate elements at the same recursion level
//    to avoid generating duplicate combinations.
// 5. If an element exceeds the remaining target, stop
//    exploring further since the array is sorted.
// 6. When the remaining target becomes 0, store the
//    current combination.
//
// Time Complexity: O(2^n)
// Space Complexity: O(n) (excluding the output)

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start,vector<int>& candidates, int target,vector <int> &combination){
            if (target == 0) {
            ans.push_back(combination);
            return;
        }
    
            for(int i=start;i<candidates.size();i++){
                if (i > start && candidates[i] == candidates[i - 1]) continue;
                if (candidates[i] > target) break;
                    combination.push_back(candidates[i]);
                    solve(i+1,candidates,target - candidates[i],combination);
                    combination.pop_back();

            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector <int> combination;
        solve(0,candidates,target,combination);
        return ans;
    }
};
