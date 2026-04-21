// LeetCode 344 - Reverse String
// Difficulty: Easy
// Topic: Strings, Two Pointers
// Approach: Two Pointer Swap
//
// Problem:
// Write a function that reverses a string.
// The input string is given as an array of characters.
//
// Approach Explanation:
// Use two pointers:
// - One at the beginning
// - One at the end
//
// Swap characters and move inward until they meet.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;

        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
