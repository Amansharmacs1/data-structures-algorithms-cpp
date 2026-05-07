// LeetCode 1523 - Count Odd Numbers in an Interval Range
// Difficulty: Easy
// Topic: Math
// Approach: Count odds using arithmetic observation (can be optimized)
//
// Problem:
// Given two integers low and high, return the count of odd numbers in the inclusive range.
//
// Approach Explanation:
// - Brute force: iterate from low to high and count odd numbers.
// - Optimization idea (not used here): use math formula instead of loop.
// - Current approach checks each number and increments count if odd.
//
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int countOdds(int low, int high) {
        int odd = 0;

        for (int i = low; i <= high; i++) {
            if (i % 2 != 0) {
                odd++;
            }
        }

        return odd;
    }
};
