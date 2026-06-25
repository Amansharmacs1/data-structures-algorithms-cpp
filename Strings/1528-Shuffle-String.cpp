// LeetCode 1528 - Shuffle String
// Difficulty: Easy
// Topic: Strings, Arrays
// Approach: Direct Index Mapping
//
// Problem:
// You are given a string s and an integer array indices,
// where indices[i] indicates the position that the
// character s[i] should occupy in the shuffled string.
//
// Approach Explanation:
// 1. Create a result string of the same length as s.
// 2. Traverse the indices array.
// 3. Place each character s[i] at position indices[i]
//    in the result string.
// 4. Return the shuffled string.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.length();
        string rev(n,' ');
        for(int i=0;i<indices.size();i++){
            int idx=indices[i];
            rev[idx]=s[i];
        }
        return rev;
    }
    
};
