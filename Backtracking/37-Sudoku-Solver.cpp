// LeetCode 37 - Sudoku Solver
// Difficulty: Hard
// Topic: Backtracking, Recursion, Matrix
// Approach: Try all valid digits using backtracking with constraint checking
//
// Problem:
// Solve a partially filled 9x9 Sudoku board such that:
// - Each row contains digits 1-9 without repetition
// - Each column contains digits 1-9 without repetition
// - Each 3x3 subgrid contains digits 1-9 without repetition
//
// Approach Explanation:
// - Use backtracking to fill empty cells ('.').
// - For each empty cell, try digits '1' to '9'.
// - Before placing a digit, check if it's safe:
//   - Not present in current row
//   - Not present in current column
//   - Not present in 3x3 subgrid
// - If valid, place digit and move forward recursively.
// - If dead end, undo (backtrack).
//
// Time Complexity: O(9^(empty cells))
// Space Complexity: O(1) extra (excluding recursion stack)

class Solution {
public:

    bool isSafe(vector<vector<char>> &board, int row, int col, char digit) {

        // check row
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == digit)
                return false;
        }

        // check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == digit)
                return false;
        }

        // check 3x3 grid
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for(int i = srow; i < srow + 3; i++) {
            for(int j = scol; j < scol + 3; j++) {
                if(board[i][j] == digit)
                    return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>> &board, int row, int col) {

        if (row == 9) return true;

        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        for (char digit = '1'; digit <= '9'; digit++) {

            if (isSafe(board, row, col, digit)) {

                board[row][col] = digit;

                if (helper(board, nextRow, nextCol))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
