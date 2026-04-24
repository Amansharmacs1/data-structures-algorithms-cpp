// LeetCode 52 - N-Queens II
// Difficulty: Hard
// Topic: Backtracking
// Approach: Recursion + Safety Check
//
// Problem:
// Given n, return the number of distinct solutions to the n-queens puzzle.
//
// Approach Explanation:
// Same as N-Queens (51), but instead of storing all boards,
// we only count valid configurations.
//
// For each row:
// - Try placing queen in each column
// - Check if it's safe (column + diagonals)
// - Recurse and backtrack
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

    void nQueens(vector<string> &board, int row, int n, int &count){
        if(row == n){
            count++;
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                nQueens(board, row + 1, n, count);
                board[row][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;

        nQueens(board, 0, n, count);
        return count;
    }
};
