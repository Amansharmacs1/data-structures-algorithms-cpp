// LeetCode 69 - Sqrt(x)
// Difficulty: Easy
// Topic: Binary Search, Math
// Approach: Linear Search
//
// Problem:
// Given a non-negative integer x, return the square root of x
// rounded down to the nearest integer.
//
// Approach Explanation:
// 1. Iterate from 1 to x.
// 2. Check if i * i equals x using division to avoid overflow.
// 3. If i exceeds the square root, return i - 1.
// 4. Return the integer part of the square root.
//
// Time Complexity: O(√x)
// Space Complexity: O(1)

class Solution {
public:
    int mySqrt(int x) {
        for(int i=1;i<=x;i++){
            
        if(i == x/i) return i;
            if(i > x/i) return i - 1;
            
        }
    
    return 0;
    }
};
