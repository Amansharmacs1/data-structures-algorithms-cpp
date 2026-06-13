 // LeetCode 832 - Flipping an Image
// Difficulty: Easy
// Topic: Arrays, Matrix
// Approach: Reverse + Invert
//
// Problem:
// Given a binary matrix, first flip each row horizontally,
// then invert every bit in the matrix.
//
// Approach Explanation:
// 1. Reverse each row of the matrix.
// 2. Invert every bit:
//    - 0 becomes 1
//    - 1 becomes 0
// 3. Return the transformed matrix.
//
// Time Complexity: O(n × m)
// Space Complexity: O(n × m)

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> res(n, vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<(m/2)+1;j++){
                // swap(image[i][j],image[i][m-j-1]);
                res[i][j] = image[i][m-1-j];
                res[i][m-1-j] = image[i][j];

                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(res[i][j]==0){
                    res[i][j]=1;
                }
                else{
                    res[i][j]=0;
                }
            }
        }
        return res;
    }
};
