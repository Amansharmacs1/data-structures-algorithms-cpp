// LeetCode 1572 - Matrix Diagonal Sum
// Difficulty: Easy
// Topic: Arrays, Matrix
// Approach: Diagonal Traversal
//
// Problem:
// Given a square matrix, return the sum of the primary
// and secondary diagonals.
//
// Approach Explanation:
// - Add elements of the primary diagonal: arr[i][i]
// - Add elements of the secondary diagonal: arr[i][n-1-i]
// - For odd-sized matrices, avoid counting the center element twice
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i][i];

            if(i != n - 1 - i) {
                sum += arr[i][n - 1 - i];
            }
        }

        return sum;
    }
};
