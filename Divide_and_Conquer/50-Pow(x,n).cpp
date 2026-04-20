// LeetCode 50 - Pow(x, n)
// Difficulty: Medium
// Topic: Divide and Conquer, Binary Exponentiation
// Approach: Fast Power (Binary Exponentiation)
//
// Problem:
// Implement pow(x, n), which calculates x raised to the power n.
//
// Approach Explanation:
// Instead of multiplying x n times (O(n)),
// we use binary exponentiation to reduce time complexity.
//
// Key idea:
// - If n is even: x^n = (x^(n/2))^2
// - If n is odd:  x^n = x * (x^(n-1))
//
// We iteratively:
// - Multiply answer when current bit is 1
// - Square x each step
// - Divide n by 2
//
// Handle negative powers by converting:
// x^(-n) = 1 / x^n
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long binform = n;

        if(n < 0){
            x = 1 / x;
            binform = (-1) * binform;
        }

        double ans = 1;

        while(binform > 0){
            if(binform % 2 == 1){
                ans = ans * x;
            }
            x = x * x;
            binform /= 2;      
        }

        return ans;
    }
};
