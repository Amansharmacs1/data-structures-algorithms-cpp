// LeetCode 2596 - Check Knight Tour Configuration
// Difficulty: Medium
// Topic: Backtracking
// Approach: DFS Simulation
//
// Problem:
// Given an n x n grid, check if it represents a valid knight's tour.
// The knight must visit every cell exactly once following valid moves.
//
// Approach Explanation:
// 1. Start from (0,0) with expected value = 0
// 2. At each step, try all 8 possible knight moves
// 3. Move only if the next cell has expectedValue + 1
// 4. Continue until reaching n*n - 1
//
// Time Complexity: O(n^2) (each cell visited once)
// Space Complexity: O(n^2) recursion stack

class Solution {
public:
    bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expectedValue){

        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expectedValue){
            return false;
        }

        if(expectedValue == n*n - 1){
            return true;
        }

        // 8 possible knight moves
        int ans1 = isValid(grid, r-2, c+1, n, expectedValue+1);
        int ans2 = isValid(grid, r-1, c+2, n, expectedValue+1);
        int ans3 = isValid(grid, r+1, c+2, n, expectedValue+1);
        int ans4 = isValid(grid, r+2, c+1, n, expectedValue+1);
        int ans5 = isValid(grid, r+2, c-1, n, expectedValue+1);
        int ans6 = isValid(grid, r+1, c-2, n, expectedValue+1);
        int ans7 = isValid(grid, r-1, c-2, n, expectedValue+1);
        int ans8 = isValid(grid, r-2, c-1, n, expectedValue+1);

        return ans1 || ans2 || ans3 || ans4 ||
               ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};
