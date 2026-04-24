// LeetCode 51 - N-Queens
// Difficulty: Hard
// Topic: Backtracking
// Approach: Recursion + Safety Check
//
// Problem:
// Place n queens on an n×n chessboard such that
// no two queens attack each other.
// Return all distinct solutions.
//
// Approach Explanation:
// We place queens row by row.
// For each row, try placing a queen in every column:
//
// Check 3 directions for safety:
// 1. Vertical (same column)
// 2. Left diagonal
// 3. Right diagonal
//
// If safe → place queen → recurse → backtrack
//
// Time Complexity: O(n!) (approx)
// Space Complexity: O(n^2)

class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n){

        // vertical
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        // left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // right diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string> &board, int row, int n,
                 vector<vector<string>> &ans){

        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);
        return ans;
    }
};
