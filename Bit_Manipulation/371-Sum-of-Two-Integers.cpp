// LeetCode 371 - Sum of Two Integers
// Difficulty: Medium
// Topic: Bit Manipulation
// Approach: Bitwise Addition (without + or -)
//
// Problem:
// Calculate the sum of two integers without using + or - operators.
//
// Approach Explanation:
// We simulate binary addition using:
// - XOR (^) → gives sum without carry
// - AND (&) → gives carry
// - Left shift (<< 1) → moves carry to correct position
//
// Repeat until carry becomes 0.
//
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;

        while(b != 0){
            carry = (a & b) << 1; // carry
            a = a ^ b;            // sum without carry
            b = carry;            // update carry
        }

        return a;
    }
};
