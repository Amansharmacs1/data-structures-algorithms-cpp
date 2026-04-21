// LeetCode 7 - Reverse Integer
// Difficulty: Medium
// Topic: Math
// Approach: Digit Extraction with Overflow Handling
//
// Problem:
// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes overflow, return 0.
//
// Approach Explanation:
// 1. Extract digits using % 10
// 2. Build reversed number using rev = rev * 10 + digit
// 3. Before adding digit, check for overflow
//
// Overflow Condition:
// If rev > INT_MAX/10 OR
// (rev == INT_MAX/10 AND digit > 7) → overflow
//
// Handle negative numbers separately.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        bool flag = false;

        if(x == INT_MIN){
            return 0;
        }

        if(x < 0){
            x = x * (-1);
            flag = true;
        }

        for(int i = x; i > 0; i /= 10){
            int d = i % 10;

            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && d > 7)) {
                return 0;
            }

            rev = rev * 10 + d;
        }

        if(flag){
            return -rev;
        }

        return rev;
    }
};
