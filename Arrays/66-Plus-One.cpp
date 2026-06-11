// LeetCode 66 - Plus One
// Difficulty: Easy
// Topic: Arrays, Math
// Approach: Digit Simulation
//
// Problem:
// Given a non-empty array of digits representing a non-negative integer,
// increment the integer by one and return the resulting array.
//
// Approach Explanation:
// - Start from the last digit.
// - If digit < 9, increment it and return.
// - If digit == 9, set it to 0 and continue.
// - If all digits are 9, insert 1 at the beginning.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
