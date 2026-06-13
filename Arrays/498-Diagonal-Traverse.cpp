// LeetCode 498 - Diagonal Traverse
// Difficulty: Medium
// Topic: Arrays, Matrix, Simulation
// Approach: Diagonal Traversal
//
// Problem:
// Return all elements of the matrix in diagonal order.
//
// Approach Explanation:
// 1. Start from the top-left cell.
// 2. Traverse diagonally in alternating directions:
//    - Up-Right
//    - Down-Left
// 3. When a boundary is reached, adjust the position
//    and switch the traversal direction.
// 4. Continue until all elements are visited.
//
// Time Complexity: O(n × m)
// Space Complexity: O(1) (excluding output array)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;
        int i = 0, j = 0;
        bool up = true;

        for (int count = 0; count < n * m; count++) {
            ans.push_back(mat[i][j]);

            if (up) {
                if (j == m - 1) {          // right boundary
                    i++;
                    up = false;
                } else if (i == 0) {       // top boundary
                    j++;
                    up = false;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == n - 1) {          // bottom boundary
                    j++;
                    up = true;
                } else if (j == 0) {       // left boundary
                    i++;
                    up = true;
                } else {
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};
