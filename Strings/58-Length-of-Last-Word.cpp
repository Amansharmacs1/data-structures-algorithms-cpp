// LeetCode 58 - Length of Last Word
// Difficulty: Easy
// Topic: Strings
// Approach: Reverse Traversal
//
// Problem:
// Given a string s consisting of words and spaces,
// return the length of the last word.
//
// Approach Explanation:
// We traverse the string from the end:
// 1. Skip trailing spaces
// 2. Count characters until we hit a space
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int len = 0;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] != ' '){
                len++;
            }
            if(s[i] == ' ' && len){
                break;
            }
            if(s[i] == ' '){
                continue;
            }
        }

        return len;
    }
};
