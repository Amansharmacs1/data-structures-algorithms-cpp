// LeetCode 77 - Combinations
// Difficulty: Medium
// Topic: Backtracking, Recursion
// Approach: Backtracking (Pick & Backtrack)
//
// Problem:
// Given two integers n and k, return all possible combinations
// of k numbers chosen from the range [1, n].
//
// Approach Explanation:
// 1. Start from number 1.
// 2. At each step, choose the current number and add it to the path.
// 3. Recursively continue with the next number.
// 4. When the path contains k numbers, store it in the answer.
// 5. Backtrack by removing the last chosen number and try the next option.
//
// Time Complexity: O(C(n, k) * k)
// Space Complexity: O(k) (excluding the output)

class Solution {
public:
 vector<vector<int>> ans;
    void solve(int start,int n,int k,vector<int> &path){
       
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++){
            path.push_back(i);
            solve(i+1,n,k,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        solve(1,n,k,path);
        return ans;
    }
};
