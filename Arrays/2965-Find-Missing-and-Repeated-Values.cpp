// LeetCode 2965 - Find Missing and Repeated Values
// Difficulty: Easy
// Topic: Arrays, Hashing, Matrix
// Approach: Hash Set + Sum Formula
//
// Problem:
// Given an n × n grid containing numbers from 1 to n²,
// one number is repeated and one number is missing.
// Return [repeated, missing].
//
// Approach Explanation:
// 1. Traverse the grid and calculate the actual sum.
// 2. Use a hash set to detect the repeated number.
// 3. Compute the expected sum of numbers from 1 to n².
// 4. Missing number = Expected Sum - (Actual Sum - Repeated Number).
// 5. Return {Repeated, Missing}.
//
// Time Complexity: O(n²)
// Space Complexity: O(n²)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> ans;
        int a=0,b=0;
        int expectedSum=( n * n * ( n * n + 1 ) ) / 2;
        int actualSum=0;
        unordered_set<int> s;
        
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        actualSum+=grid[i][j];
        if(s.find(grid[i][j])!=s.end()){
            a=grid[i][j];
            ans.push_back(a);
            
        }
        s.insert(grid[i][j]);
       }  
       }

       b=expectedSum-(actualSum-a);
       ans.push_back(b);

       return ans;
    }
};
