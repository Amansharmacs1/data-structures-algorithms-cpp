// LeetCode 1392 - Longest Happy Prefix
// Difficulty: Hard
// Topic: Strings, KMP (Prefix Function)
// Approach: Compute LPS Array
//
// Problem:
// Find the longest prefix of the string that is also a suffix,
// excluding the entire string itself.
//
// Approach Explanation:
// 1. Build the LPS (Longest Prefix Suffix) array using the KMP algorithm.
// 2. The LPS value at the last index represents the length of the
//    longest proper prefix which is also a suffix.
// 3. Return the substring from index 0 to that length.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string longestPrefix(string s) {
        int prefix=0;
        int suffix=1;
    
    vector <int> lps(s.size(),0);
    
    while(suffix<s.size()){
        if(s[prefix]==s[suffix]){
            lps[suffix]=prefix+1;
            suffix++;
            prefix++;
        }
        else{
            if(prefix==0){
                lps[suffix]=0;
                suffix++;
            }
            else{
                prefix=lps[prefix-1];
            }
        }
    }
    return s.substr(0, lps[s.size() - 1]);
    }
};
