// LeetCode 509 - Fibonacci Number
// Difficulty: Easy
// Topic: Dynamic Programming
// Approach: Iterative (Space Optimized DP)
//
// Problem:
// Given n, return the nth Fibonacci number.
//
// Fibonacci series:
// F(0) = 0, F(1) = 1
// F(n) = F(n-1) + F(n-2)
//
// Approach Explanation:
// Instead of recursion (which is slow),
// we use iteration and store only last two values.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int n1 = 0;
        int n2 = 1;
        int n3 = 0;

        for(int i = 1; i < n; i++){
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }

        return n3;
    }
};
