// LeetCode 3 - Longest Substring Without Repeating Characters
// Difficulty: Medium
// Topic: Sliding Window, Hashing, Strings
// Approach: Sliding Window + Hash Set
//
// Problem:
// Given a string, find the length of the longest substring
// without repeating characters.
//
// Approach Explanation:
// 1. Maintain a sliding window using two pointers.
// 2. Use a hash set to store unique characters in the current window.
// 3. Expand the window by moving the right pointer.
// 4. If a duplicate character is found, shrink the window
//    from the left until the duplicate is removed.
// 5. Keep track of the maximum window length.
//
// Time Complexity: O(n)
// Space Complexity: O(min(n, charset))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0,right=0,maxLen=0;
        unordered_set<char> charSet;

        while(right<n){
            if(charSet.find(s[right])==charSet.end()){
                charSet.insert(s[right]);
                maxLen=max(maxLen,right-left+1);
                right++;
            }
            else{
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
