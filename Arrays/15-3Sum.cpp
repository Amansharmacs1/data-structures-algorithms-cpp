// LeetCode 15 - 3Sum
// Difficulty: Medium
// Topic: Arrays, Sorting, Two Pointers
// Approach: Sorting + Two Pointers
//
// Problem:
// Find all unique triplets [nums[i], nums[j], nums[k]]
// such that their sum is equal to 0.
//
// Approach Explanation:
// 1. Sort the array.
// 2. Fix one element at a time.
// 3. Use two pointers (left and right) to find the remaining
//    two elements whose sum equals -nums[i].
// 4. Skip duplicate elements to avoid repeated triplets.
// 5. Store all unique triplets.
//
// Time Complexity: O(n²)
// Space Complexity: O(1) (excluding output)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=n-1;
            int target=-nums[i];
            while(left<right){
                if(nums[left]+nums[right]==target){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(target>nums[left]+nums[right]){
                    left++;
                }
                else{
                    right--;
                }
                
            }
        }
        return res;
    }
};
