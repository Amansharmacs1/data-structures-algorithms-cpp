// LeetCode 567 - Permutation in String
// Difficulty: Medium
// Topic: Sliding Window, Strings, Hashing
// Approach: Frequency Count + Sliding Window
//
// Problem:
// Given two strings s1 and s2, return true if s2 contains
// a permutation of s1 as a substring.
//
// Approach Explanation:
// 1. Count the frequency of characters in s1.
// 2. Maintain a sliding window of length s1.size() over s2.
// 3. Track the frequency of characters in the current window.
// 4. Compare the two frequency arrays.
// 5. If they match, a permutation exists.
//
// Time Complexity: O(26 × n) ≈ O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isFreqSame(int freq1[],int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        int windowSize=s1.size();
        
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }

            for(int i=0;i<s2.length();i++){
            int windowIdx=0;
            int idx=i;
            int windowFreq[26]={0};

            while(windowSize>windowIdx && idx<s2.length()){
                windowFreq[s2[idx]-'a']++;
                windowIdx++;
                idx++;
            }
            if(isFreqSame(freq,windowFreq)){
                return true;
            }
        }
return false;
    } 
};
