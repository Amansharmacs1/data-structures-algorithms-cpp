// LeetCode 921 - Minimum Add to Make Parentheses Valid
// Difficulty: Medium
// Topic: Stack, String, Greedy
// Approach: Balance Counter
//
// Problem:
// Given a parentheses string, return the minimum number of
// parentheses that must be added to make the string valid.
//
// Approach Explanation:
// 1. Maintain a balance counter representing unmatched '('.
// 2. For every '(':
//    - Increment the balance.
// 3. For every ')':
//    - If there is an unmatched '(', match it by decrementing balance.
//    - Otherwise, an extra '(' is needed, so increment the answer.
// 4. After processing the string, any remaining unmatched '('
//    must be closed.
// 5. Return answer + balance.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0;
        int add=0;
        for(char ch : s){
            if(ch=='('){
                bal++;
            }
            else{
                if(bal>0){
                    bal--;
                }
                else{
                    add++;
                }
            }
        }
        return bal+add;
    }
};
