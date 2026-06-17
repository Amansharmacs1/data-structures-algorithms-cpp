// LeetCode 74 - Search a 2D Matrix
// Difficulty: Medium
// Topic: Binary Search, Matrix
// Approach: Row Selection + Binary Search
//
// Problem:
// Given an m x n matrix with sorted rows and
// each row's first element greater than the previous row's last element,
// determine if a target exists in the matrix.
//
// Approach Explanation:
// 1. Identify the row that can contain the target.
// 2. Perform binary search on that row.
// 3. Return true if target is found, otherwise false.
//
// Time Complexity: O(n + log m)
// Space Complexity: O(1)
class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int target,int row){
        int m=matrix[0].size();
        int start=0;
        int end=m-1;
        while(start<=end){

            int mid=start+(end-start)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        //edge case
        if(target<matrix[0][0]) return false;
         if(target>matrix[n-1][m-1]) return false;
        
        for(int i=0;i<n;i++){
            if(target>=matrix[i][0] && matrix[i][m-1]>=target){
                return searchRow(matrix,target,i);
            }
            else{
                continue;
            }
        }
        return false;

    }
};
