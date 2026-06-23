// LeetCode 1910 - Remove All Occurrences of a Substring
// Difficulty: Medium
// Topic: Strings
// Approach: String as Stack
//
// Problem:
// Given two strings s and part, repeatedly remove the
// leftmost occurrence of part from s until it no longer exists.
//
// Approach Explanation:
// 1. Traverse the string character by character.
// 2. Build the result string incrementally.
// 3. After adding each character, check whether the suffix
//    of the result matches 'part'.
// 4. If it matches, remove that suffix.
// 5. Continue until all characters are processed.
//
// Time Complexity: O(n × m)
// Space Complexity: O(n)
//
// where:
// n = length of s
// m = length of part

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res="";
        for( char ch : s){
            res+=ch;

            if(res.length()>=part.length() && res.substr(res.size()-part.size())==part){
                res.erase(res.size()-part.size());


            }
        }
        return res;
    }
};
