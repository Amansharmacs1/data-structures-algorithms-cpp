// LeetCode 125 - Valid Palindrome
// Difficulty: Easy
// Topic: Strings, Two Pointers
// Approach: Two Pointers
//
// Problem:
// Given a string, determine if it is a palindrome,
// considering only alphanumeric characters and ignoring cases.
//
// Approach Explanation:
// 1. Initialize two pointers at the beginning and end of the string.
// 2. Skip non-alphanumeric characters from both ends.
// 3. Compare the lowercase versions of the current characters.
// 4. If they differ, return false.
// 5. Move both pointers inward until they cross.
// 6. If all comparisons match, return true.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int st=0;
        int end=n-1;
        while(st<end){
            if(!isalnum(s[st])){
                st++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};
