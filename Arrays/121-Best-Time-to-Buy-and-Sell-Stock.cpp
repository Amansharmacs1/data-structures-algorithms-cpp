// LeetCode 121 - Best Time to Buy and Sell Stock
// Difficulty: Easy
// Topic: Arrays, Greedy
// Approach: Track Minimum Price
//
// Problem:
// Given an array where prices[i] is the price of a stock on day i,
// find the maximum profit by choosing a single day to buy and a
// later day to sell.
//
// Approach Explanation:
// 1. Keep track of the minimum stock price seen so far.
// 2. For each day's price, calculate the profit if sold on that day.
// 3. Update the maximum profit whenever a larger profit is found.
// 4. Update the minimum buying price when a lower price appears.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxProfit=0;
        for(int val : prices){
            if(buy<val){
                int profit=val-buy;
                maxProfit=max(maxProfit,profit);
            }
            if(buy>val){
                buy=val;
            }
        }
        return maxProfit;
        
    }
};
