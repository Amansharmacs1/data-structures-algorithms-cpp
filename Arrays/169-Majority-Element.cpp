// LeetCode 169 - Majority Element
// Difficulty: Easy
// Topic: Arrays
// Approach: Boyer-Moore Voting Algorithm
//
// Problem:
// Find the element that appears more than ⌊n/2⌋ times.
//
// Approach Explanation:
// 1. Maintain a candidate and a count.
// 2. If count becomes 0, choose the current element as candidate.
// 3. Increment count if current element equals candidate.
// 4. Otherwise, decrement count.
// 5. The remaining candidate is the majority element.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int count=0;
        for(int val : nums){
            if(count==0){
                maj=val;

            }
            if(maj==val){
                count++;
            }
            else{
                count--;
            }
        }
        return maj;
    }
};
