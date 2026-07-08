// LeetCode 70 - Climbing Stairs
// Difficulty: Easy
// Topic: Dynamic Programming
// Approach: Bottom-Up DP
//
// Problem:
// You are climbing a staircase with n steps.
// Each time, you can climb either 1 or 2 steps.
// Return the number of distinct ways to reach the top.
//
// Approach Explanation:
// 1. Let dp[i] represent the number of ways to reach step i.
// 2. Base cases:
//    - dp[1] = 1
//    - dp[2] = 2
// 3. For every step from 3 to n:
//    dp[i] = dp[i-1] + dp[i-2]
// 4. Return dp[n].
//
// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
public:
    int climbStairs(int n) {
        vector<int> temp(n+1);
        if( n==1 || n==2 || n==3 ){
            return n;
        }
        temp[0]=0;
        temp[1]=1;
        temp[2]=2;

        for(int i=3;i<=n;i++){
            temp[i]=temp[i-1]+temp[i-2];
        }
        return temp[n];

    }
};
