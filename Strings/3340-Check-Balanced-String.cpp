// LeetCode 3340 - Check Balanced String
// Difficulty: Easy
// Topic: Strings
// Approach: Index-based Sum Comparison
//
// Problem:
// Given a numeric string, check if the sum of digits at even indices
// is equal to the sum of digits at odd indices.
//
// Approach Explanation:
// 1. Traverse the string
// 2. Add digits at odd indices
// 3. Subtract digits at even indices
// 4. If final sum is 0 → balanced
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isBalanced(string num) {
        int sum = 0;
        int n = num.length();

        for(int i = 0; i < n; i++){
            if(i & 1){
                sum += num[i] - '0';
            } else {
                sum -= num[i] - '0';
            }
        }

        return sum == 0;
    }
};
