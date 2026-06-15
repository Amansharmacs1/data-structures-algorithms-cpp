// LeetCode 11 - Container With Most Water
// Difficulty: Medium
// Topic: Arrays, Two Pointers
// Approach: Two Pointers
//
// Problem:
// Given an array of heights, find two lines that together
// with the x-axis form a container that holds the most water.
//
// Approach Explanation:
// 1. Place two pointers at the beginning and end of the array.
// 2. Calculate the area formed by the two lines.
// 3. Update the maximum area found so far.
// 4. Move the pointer with the smaller height inward,
//    since it is the limiting factor.
// 5. Repeat until the pointers meet.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        long int maxArea=0;
        while(left<right){
            int h=min(height[left],height[right]);
            long int area=(right-left)*h;
            maxArea=max(maxArea,area);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxArea;
    }
};
