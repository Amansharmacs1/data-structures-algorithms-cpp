// LeetCode 242 - Valid Anagram
// Difficulty: Easy
// Topic: Strings, Hashing
// Approach: Frequency Counting
//
// Problem:
// Given two strings s and t, determine whether t
// is an anagram of s.
//
// Approach Explanation:
// 1. Create two frequency arrays of size 26.
// 2. Count the occurrences of each character in s.
// 3. Count the occurrences of each character in t.
// 4. Compare the frequency arrays.
// 5. If all frequencies match, the strings are anagrams.
//
// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> freqS(26,0);
        vector <int> freqT(26,0);
        for(int i=0;i<s.length();i++){
            freqS[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            freqT[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freqS[i]!=freqT[i]){
                return false;
            }
        }
        return true;
    }
};
