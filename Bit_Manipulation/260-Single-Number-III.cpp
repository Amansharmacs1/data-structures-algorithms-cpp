// LeetCode 260 - Single Number III
// Difficulty: Medium
// Topic: Bit Manipulation
// Approach: XOR + Rightmost Set Bit
//
// Problem:
// Every element appears twice except for two elements.
// Find the two unique elements.
//
// Approach Explanation:
// 1. XOR all numbers to get:
//    xorr = a ^ b
//    where a and b are the unique numbers.
// 2. Find the rightmost set bit in xorr.
//    This bit differs between a and b.
// 3. Divide numbers into two groups based on this bit.
// 4. XOR numbers within each group to obtain a and b.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int xorr=0;
        
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
           unsigned int diff = (unsigned int)xorr & (-(unsigned int)xorr);
        int a=0;
        int b=0;
        for(int num : nums){
            if(num & diff){
                a^=num;
            }
            else{
                b^=num;
            }
        }
        return {a,b};
    }
};
