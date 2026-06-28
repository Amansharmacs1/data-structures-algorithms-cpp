// LeetCode 33 - Search in Rotated Sorted Array
// Difficulty: Medium
// Topic: Binary Search, Array
// Approach: Modified Binary Search
//
// Problem:
// Given a rotated sorted array of distinct integers, return the
// index of the target if it exists; otherwise, return -1.
//
// Approach Explanation:
// 1. Perform binary search.
// 2. At every step, determine which half is sorted.
// 3. If the target lies within the sorted half, search there.
// 4. Otherwise, search the other half.
// 5. Repeat until the target is found or the search space becomes empty.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }

            //left
            if(nums[start]<=nums[mid]){
                if(nums[start] <= target && target <= nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }

            //right
            else{
                if(nums[mid] <= target && target <= nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            
        }
    return -1;
    }
};
