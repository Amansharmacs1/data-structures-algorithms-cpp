// LeetCode 79 - Word Search
// Difficulty: Medium
// Topic: Backtracking, Matrix, DFS
// Approach: DFS + Backtracking
//
// Problem:
// Given an m × n board of characters and a word,
// determine if the word exists in the grid.
//
// Approach Explanation:
// 1. Traverse every cell of the board.
// 2. Start a DFS whenever the first character matches.
// 3. Explore all four directions (up, down, left, right).
// 4. Mark the current cell as visited to avoid revisiting it.
// 5. Backtrack by restoring the original character after exploration.
// 6. Return true if the complete word is found.
//
// Time Complexity: O(m × n × 4^L)
// Space Complexity: O(L)
//
// where:
// m = number of rows
// n = number of columns
// L = length of the word

class Solution {
public:

    bool helper(vector<vector<char>>& board, string word,int i,int j,int n,int m,int k){
        if(k>=word.size()) return true;
   if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '.' || word[k] != board[i][j]) return false;
        board[i][j]='.';
        bool temp =false;
        int x[4]={0,0,-1,1};
        int y[4]={-1,1,0,0};
        for(int idx=0;idx<4;idx++){
            temp=temp || helper(board,word,i+x[idx],j+y[idx],n,m,k+1);
        }
        board[i][j]=word[k];
        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        if(n==0) return false;
        int m=board[0].size();
        if(word.size()==0) return false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(helper(board,word,i,j,n,m,0)) return true;
                }
            }
        }
        return false;
    }
};
