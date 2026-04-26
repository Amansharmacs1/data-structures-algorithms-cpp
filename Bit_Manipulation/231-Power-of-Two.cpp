// LeetCode 231 - Power of Two
// Difficulty: Easy
// Topic: Bit Manipulation
// Approach: Bit Trick
//
// Problem:
// Given an integer n, return true if it is a power of two.
// Otherwise, return false.
//
// Approach Explanation:
// A power of two has only one '1' bit in binary.
//
// Trick:
// n & (n - 1) removes the lowest set bit.
// If result becomes 0 → only one set bit existed.
//
// Example:
// 8  -> 1000
// 7  -> 0111
// AND -> 0000
//
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
