// LeetCode 131 - Palindrome Partitioning
// Difficulty: Medium
// Topic: Backtracking, Strings
// Approach: Recursion + Palindrome Check
//
// Problem:
// Given a string s, partition it such that every substring
// of the partition is a palindrome.
// Return all possible palindrome partitionings.
//
// Approach Explanation:
// 1. Try every possible prefix
// 2. If prefix is palindrome → include it
// 3. Recurse on remaining string
// 4. Backtrack to explore other partitions
//
// Time Complexity: O(2^n * n)
// Space Complexity: O(n)

class Solution {
public:
    bool isPalind(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getAllParts(string s, vector<string> &partitions,
                     vector<vector<string>> &ans){

        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i + 1);

            if(isPalind(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);
        return ans;
    }
};
