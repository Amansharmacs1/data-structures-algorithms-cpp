// LeetCode 31 - Next Permutation
// Difficulty: Medium
// Topic: Arrays, Two Pointers
// Approach: Pivot + Reverse
//
// Problem:
// Rearrange numbers into the lexicographically next greater permutation.
// If such arrangement is not possible, rearrange it to the lowest possible order.
//
// Approach Explanation:
// 1. Find the first decreasing element from the right (pivot).
// 2. If no pivot exists, reverse the entire array.
// 3. Find the next greater element than the pivot from the right.
// 4. Swap the pivot with that element.
// 5. Reverse the suffix after the pivot to obtain the next permutation.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pivot=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
           reverse(nums.begin(), nums.end());
           return;
        }
        for(int i=n-1;i>pivot;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        int left=pivot+1;
        int right=n-1;
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }

    }
};
