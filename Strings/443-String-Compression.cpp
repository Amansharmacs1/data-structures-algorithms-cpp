// LeetCode 443 - String Compression
// Difficulty: Medium
// Topic: Strings, Two Pointers
// Approach: In-Place Compression
//
// Problem:
// Given an array of characters, compress it in-place by
// replacing consecutive repeated characters with the
// character followed by its count (if greater than 1).
//
// Approach Explanation:
// 1. Traverse the character array and count consecutive
//    occurrences of each character.
// 2. Write the character to the compressed position.
// 3. If its count is greater than 1, convert the count
//    to a string and write each digit separately.
// 4. Continue until all groups are processed.
// 5. Resize the array and return the compressed length.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int compress(vector<char>& str) {
        int n=str.size();
        int idx=0;
        if(n==1){
            return 1;
        }
        for(int i=0;i<n;i++){
            char ch=str[i];
            int count=0;
            while(i<n && str[i]==ch){
                i++;
                count++;
            }
            if(count==1){
                str[idx]=ch;
                idx++;
            }
            else{
                string digit=to_string(count);
                str[idx]=ch;
                idx++;
                for(char val : digit){
                    str[idx]=val;
                    idx++;
                }
            }
        i--;
        }
        str.resize(idx);
        return str.size();
    }
};
