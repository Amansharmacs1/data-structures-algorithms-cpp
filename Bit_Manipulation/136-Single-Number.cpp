// LeetCode 136 - Single Number
// Difficulty: Easy
// Topic: Bit Manipulation
// Approach: XOR
//
// Problem:
// Every element appears twice except for one.
// Find that single element.
//
// Approach Explanation:
// 1. XOR all elements of the array.
// 2. Duplicate elements cancel each other out:
//    x ^ x = 0
// 3. The remaining value is the unique element.
// 4. Return the result.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int val :nums){
            res=res^val;
        }
        return res;
    }
};
