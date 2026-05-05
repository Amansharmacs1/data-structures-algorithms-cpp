// LeetCode 12 - Integer to Roman
// Difficulty: Medium
// Topic: Strings, Greedy
// Approach: Greedy Mapping
//
// Problem:
// Convert an integer to its Roman numeral representation.
//
// Approach Explanation:
// - Maintain arrays of values and corresponding symbols
// - Always pick the largest possible value ≤ num
// - Subtract it and append its symbol
// - Repeat until num becomes 0
//
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {
            1000, 900, 500, 400, 100, 90,
            50, 40, 10, 9, 5, 4, 1
        };

        vector<string> symbols = {
            "M", "CM", "D", "CD", "C", "XC",
            "L", "XL", "X", "IX", "V", "IV", "I"
        };

        string result = "";

        for(int i = 0; i < values.size(); i++){
            while(num >= values[i]){
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};
