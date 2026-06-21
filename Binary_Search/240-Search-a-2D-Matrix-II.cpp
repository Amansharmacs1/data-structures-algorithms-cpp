// LeetCode 240 - Search a 2D Matrix II
// Difficulty: Medium
// Topic: Binary Search, Matrix
// Approach: Staircase Search
//
// Problem:
// Given an m × n matrix where each row is sorted in ascending order
// from left to right and each column is sorted in ascending order
// from top to bottom, determine if the target exists in the matrix.
//
// Approach Explanation:
// 1. Start from the top-right corner of the matrix.
// 2. If the current element equals the target, return true.
// 3. If the current element is greater than the target,
//    move left.
// 4. Otherwise, move down.
// 5. Continue until the target is found or the search
//    goes out of bounds.
//
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
         int m=arr.size();
    int n=arr[0].size();
    int r=0;
    int c=n-1;
    
   while(r<m && c>=0){
    if(arr[r][c]==target){
        return true;
    }
    else if(target<arr[r][c]){
        c--;
    }
    else{
        r++;
    }
   }
   return false;
    }
};
