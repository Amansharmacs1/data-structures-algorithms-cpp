// LeetCode 9 - Palindrome Number
// Difficulty: Easy
// Topic: Math
// Approach: Reverse Integer
//
// Problem:
// Given an integer x, return true if x is a palindrome,
// and false otherwise.
//
// Approach Explanation:
// We reverse the digits of the number and compare it with original.
// If both are equal → palindrome
//
// Steps:
// 1. Extract last digit using % 10
// 2. Build reversed number
// 3. Compare with original number
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;

        for(long i = x; i > 0; i /= 10){
            int d = i % 10;
            rev = rev * 10 + d;
        }

        return rev == x;
    }
};
