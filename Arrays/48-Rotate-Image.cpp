// LeetCode 48 - Rotate Image
// Difficulty: Medium
// Topic: Arrays, Matrix
// Approach: Transpose + Reverse Rows
//
// Problem:
// Rotate an n × n matrix by 90 degrees clockwise in-place.
//
// Approach Explanation:
// 1. Transpose the matrix:
//    matrix[i][j] ↔ matrix[j][i]
// 2. Reverse each row.
// 3. The combination of transpose and row reversal
//    results in a 90° clockwise rotation.

// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // Step 1: Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
    
    }
};
