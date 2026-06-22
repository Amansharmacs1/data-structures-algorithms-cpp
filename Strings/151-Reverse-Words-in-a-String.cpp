// LeetCode 151 - Reverse Words in a String
// Difficulty: Medium
// Topic: Strings, Two Pointers
// Approach: Split + Reverse Order
//
// Problem:
// Given an input string, reverse the order of the words.
// Remove leading, trailing, and extra spaces between words.
//
// Approach Explanation:
// 1. Traverse the string and extract each word.
// 2. Ignore multiple consecutive spaces.
// 3. Store each word in a vector.
// 4. Traverse the vector in reverse order.
// 5. Join the words with a single space.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string reverseWords(string s) {
        vector<string> rev;
        string ans="";
        string word="";

        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else{
                if(word!=""){
                rev.push_back(word);
                word="";
                }
            }
        }
        if(word!=""){
            rev.push_back(word);
        }

        for(int i=rev.size()-1;i>=0;i--){
            ans+=rev[i];
            if(i!=0){
            ans+=" ";
            }
        }
        return ans;
    }
};
