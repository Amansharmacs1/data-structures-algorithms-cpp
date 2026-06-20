// LeetCode 54 - Spiral Matrix
// Difficulty: Medium
// Topic: Arrays, Matrix, Simulation
// Approach: Boundary Traversal
//
// Problem:
// Given an m × n matrix, return all elements
// in spiral order.
//
// Approach Explanation:
// 1. Maintain four boundaries:
//    - top
//    - bottom
//    - left
//    - right
// 2. Traverse:
//    - Left → Right
//    - Top → Bottom
//    - Right → Left
//    - Bottom → Top
// 3. After each traversal, update the corresponding boundary.
// 4. Continue until all elements have been visited.
//
// Time Complexity: O(m × n)
// Space Complexity: O(1) (excluding output array)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
       vector<int> ans;
       int top=0;
       int bottom=arr.size()-1;
       int left=0;
       int right=arr[0].size()-1;
       int count=0;
       int max=(bottom)*(right);
       while(count<=max){
        //top
        for(int i=left;count<=max && i<=right;i++){
            ans.push_back(arr[top][i]);
            count++;
        }
        top++;
        for(int i=top;count<=max && i<=bottom;i++){
            ans.push_back(arr[i][right]);
            count++;
        }
        right--;
        for(int i=right;count<=max && i>=left;i-){
            ans.push_back(arr[bottom][i]);
            count++;
        }
        bottom--;
        for(int i=bottom;count<=max && i>=top;i--){
            ans.push_back(arr[i][left]);
            count++;
        }
        left++;

       }
       return ansl
    }
};
