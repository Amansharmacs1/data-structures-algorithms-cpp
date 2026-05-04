// LeetCode 39 - Combination Sum
// Approach: Backtracking (No duplicates generation)

class Solution {
public:
    void solve(vector<int>& arr, int target, int idx,
               vector<int>& path,
               vector<vector<int>>& ans){

        if(target == 0){
            ans.push_back(path);
            return;
        }

        if(idx == arr.size() || target < 0){
            return;
        }

        // include current element (stay at same index)
        path.push_back(arr[idx]);
        solve(arr, target - arr[idx], idx, path, ans);

        // backtrack
        path.pop_back();

        // exclude current element (move ahead)
        solve(arr, target, idx + 1, path, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(arr, target, 0, path, ans);
        return ans;
    }
};
