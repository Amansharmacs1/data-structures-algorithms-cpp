// LeetCode 521 - Longest Uncommon Subsequence I
// Difficulty: Easy
// Topic: Strings
// Approach: Observation / Greedy
//
// Problem:
// Given two strings a and b, return the length of the longest
// uncommon subsequence between them.
// If no such subsequence exists, return -1.
//
// Key Observation:
// - If a == b → no uncommon subsequence → return -1
// - If a != b → the longer string itself is the answer
//
// Why?
// Because the longer string cannot be a subsequence of the shorter one.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;
        return max(a.length(), b.length());
    }
};
