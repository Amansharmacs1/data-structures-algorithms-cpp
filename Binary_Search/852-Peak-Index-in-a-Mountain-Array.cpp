// LeetCode 852 - Peak Index in a Mountain Array
// Difficulty: Medium
// Topic: Binary Search, Array
// Approach: Binary Search on Mountain Array
//
// Problem:
// Given a mountain array, return the index of its peak element.
//
// Approach Explanation:
// 1. Use binary search on the array.
// 2. If arr[mid] < arr[mid + 1], the peak lies on the right.
// 3. Otherwise, the peak lies on the left (including mid).
// 4. Continue until the search space shrinks to a single element,
//    which is the peak.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        while(start<end){
            int mid=start+(end-start)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]<arr[mid+1]){
                    start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return -1;
    }
};
