// LeetCode 541 - Reverse String II
// Difficulty: Easy
// Topic: Strings, Two Pointers
// Approach: Reverse Every 2k Characters
//
// Problem:
// Given a string s and an integer k, reverse the first k
// characters for every 2k characters counting from the start.
//
// Approach Explanation:
// 1. Traverse the string in blocks of size 2k.
// 2. For each block, determine how many characters to reverse:
//    - Reverse the first k characters if at least k exist.
//    - Otherwise, reverse all remaining characters.
// 3. Swap characters using two pointers.
// 4. Continue until the end of the string.
//
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        string ans=s;
        for(int i=0;i<n;i+=2*k){
            int idx=0;
            int limit = min(k, n - i);
            // int limit=k;
            int p=limit-1;

            while(idx < limit/2){
                swap(ans[i + idx], ans[i + p]);
                idx++;
                p--;
            }
        }
        return ans;
    }
};
