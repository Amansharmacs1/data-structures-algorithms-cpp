// LeetCode 73 - Set Matrix Zeroes
// Difficulty: Medium
// Topic: Arrays, Matrix
// Approach: Store Zero Positions
//
// Problem:
// Given an m × n matrix, if an element is 0,
// set its entire row and column to 0 in-place.
//
// Approach Explanation:
// 1. Traverse the matrix and store the positions of all zeroes.
// 2. For each stored position, set its entire row and column to zero.
// 3. Return the modified matrix.
//
// Time Complexity: O((m × n) × (m + n))
// Space Complexity: O(k)
// where k is the number of zeroes.

class Solution {
public:
    void ChangeMatrix(vector<vector<int>>& matrix,int row,int col){
         for(int i=0;i<matrix[0].size();i++){
            matrix[row][i]=0;
         }
         for(int i=0;i<matrix.size();i++){
            matrix[i][col]=0;
         }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeroes;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    zeroes.push_back({i,j});
                }
            }
        }

        for( auto it : zeroes){
            ChangeMatrix(matrix,it.first,it.second);
        }
        

    }
};
