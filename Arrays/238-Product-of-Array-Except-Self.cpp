// LeetCode 238 - Product of Array Except Self
// Difficulty: Medium
// Topic: Arrays, Prefix Product
// Approach: Prefix Product + Suffix Product
//
// Problem:
// Given an integer array nums, return an array answer such that
// answer[i] is equal to the product of all the elements of nums
// except nums[i], without using division.
//
// Approach Explanation:
// 1. Compute prefix products and store them in the answer array.
// 2. Traverse from right to left while maintaining a suffix product.
// 3. Multiply each prefix product with the current suffix product.
// 4. Update the suffix product for the next iteration.
// 5. Return the resulting array.
//
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding the output array)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans(n,1);

        for(int i=1;i<n;i++){
        ans[i]=ans[i-1]*nums[i-1];
        }
        int suffix=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=ans[i]*suffix;
            suffix*=nums[i];
        }
        return ans;
    }
};
