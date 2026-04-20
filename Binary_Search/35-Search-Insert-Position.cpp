// LeetCode 35 - Search Insert Position
// Difficulty: Easy
// Topic: Binary Search, Arrays
// Approach: Iterative Binary Search
//
// Problem:
// Given a sorted array of distinct integers and a target value,
// return the index if the target is found.
// If not, return the index where it would be inserted.
//
// Approach Explanation:
// We use binary search to find the target.
// If found → return index
// If not found → 'start' will point to correct insertion position
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while(start <= end){
            int mid = (start + end) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};
