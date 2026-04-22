// LeetCode 28 - Find the Index of the First Occurrence in a String
// Difficulty: Easy
// Topic: Strings
// Approach: Brute Force (Substring Matching)
//
// Problem:
// Given two strings haystack and needle,
// return the index of the first occurrence of needle in haystack.
// If not found, return -1.
//
// Approach Explanation:
// We try every possible starting index in haystack:
// 1. If first character matches
// 2. Check the rest of the substring
// 3. If all characters match → return index
//
// Time Complexity: O(n * m)
// Space Complexity: O(1)

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();

        if(n2 == 0) return 0;

        for(int i = 0; i <= n1 - n2; i++){
            bool flag = true;

            for(int j = 0; j < n2; j++){
                if(haystack[i + j] != needle[j]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                return i;
            }
        }

        return -1;
    }
};
