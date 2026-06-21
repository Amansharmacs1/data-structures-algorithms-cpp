// LeetCode 42 - Trapping Rain Water
// Difficulty: Hard
// Topic: Arrays, Two Pointers
// Approach: Two Pointers + Left/Right Maximum
//
// Problem:
// Given an array representing the elevation map,
// compute how much rainwater can be trapped after raining.
//
// Approach Explanation:
// 1. Initialize two pointers at the beginning and end of the array.
// 2. Maintain the maximum height seen so far from both sides.
// 3. Compare the left and right maximum heights.
// 4. Move the pointer with the smaller maximum inward.
// 5. Water trapped at a position is the difference between
//    the current maximum and the bar height.
// 6. Accumulate the trapped water and return the total.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int trap(vector<int>& arr) {
    int n=arr.size();
    int l=0,r=n-1;
    int lmax=0,rmax=0;
    int ans=0; 

    while(l<r){
        lmax=max(lmax,arr[l]);
        rmax=max(rmax,arr[r]);
        if(lmax<rmax){
            ans+=(lmax-arr[l]);
            l++;
        }
        else{
        ans+=(rmax-arr[r]);
            r--;
        }
    }
    return ans;
    }
};
