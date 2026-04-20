// LeetCode 704 - Binary Search
// Difficulty: Easy
// Topic: Binary Search, Arrays
// Approach: Iterative Binary Search
//
// Problem:
// Given a sorted array of integers and a target value,
// return its index if found, otherwise return -1.
//
// Approach Explanation:
// We repeatedly divide the search space into halves.
// - If target is found → return index
// - If target is smaller → search left half
// - If target is larger → search right half
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while(start <= end){
            int mid = (start + end) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return -1;
    }
};
