// LeetCode 13 - Roman to Integer
// Difficulty: Easy
// Topic: Strings, Hashing
// Approach: Greedy (Left to Right)
//
// Problem:
// Convert a Roman numeral string to an integer.
//
// Approach Explanation:
// - Traverse the string from left to right
// - If current value < next value → subtract
// - Otherwise → add
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I',1},{'V',5},{'X',10},{'L',50},
            {'C',100},{'D',500},{'M',1000}
        };

        int sum = 0;

        for(int i = 0; i < s.length(); i++){
            if(i + 1 < s.length() && mp[s[i]] < mp[s[i + 1]]){
                sum -= mp[s[i]];
            } else {
                sum += mp[s[i]];
            }
        }

        return sum;
    }
};
