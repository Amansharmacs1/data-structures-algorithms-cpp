// LeetCode 14 - Longest Common Prefix
// Difficulty: Easy
// Topic: Strings, Sorting
// Approach: Sort and Compare First & Last String
//
// Problem:
// Given an array of strings, find the longest common prefix
// shared among all the strings.
//
// Approach Explanation:
// 1. Sort the array of strings lexicographically.
// 2. After sorting, only the first and last strings need to be compared.
// 3. Find the common prefix between these two strings.
// 4. This prefix is the longest common prefix of the entire array.
//
// Why?
// Sorting places the most different strings at the ends.
// If the first and last strings share a prefix, every string
// between them must also share that prefix.
//
// Time Complexity: O(n log n * m)
// Space Complexity: O(1) (excluding sorting implementation)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        sort(strs.begin(),strs.end());
        int lastIdx=strs.size()-1;
        for(int i=0;i<strs[0].length();i++){
            if(strs[0][i]!=strs[lastIdx][i]){
                break;
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};
