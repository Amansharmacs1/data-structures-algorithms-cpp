// LeetCode 75 - Sort Colors
// Difficulty: Medium
// Topic: Arrays, Two Pointers
// Approach: Dutch National Flag Algorithm
//
// Problem:
// Sort an array containing only 0s, 1s, and 2s in-place
// without using the library sort function.
//
// Approach Explanation:
// 1. Maintain three pointers:
//    - low: position for next 0
//    - mid: current element
//    - high: position for next 2
// 2. If nums[mid] == 0:
//    swap with low and move both pointers.
// 3. If nums[mid] == 1:
//    move mid forward.
// 4. If nums[mid] == 2:
//    swap with high and decrease high.
// 5. Continue until mid > high.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;

            }
            else{
                mid++;
            }

        }

    }
};
