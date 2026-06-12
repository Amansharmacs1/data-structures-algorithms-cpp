// LeetCode 724 - Find Pivot Index
// Difficulty: Easy
// Topic: Arrays, Prefix Sum
// Approach: Running Prefix Sum
//
// Problem:
// Find the pivot index where the sum of elements to the left
// equals the sum of elements to the right.
//
// Approach Explanation:
// 1. Compute total sum of the array.
// 2. Maintain a running left sum.
// 3. Right sum = total - left - current element.
// 4. If left sum == right sum, return the index.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        int total = 0;

        for(int x : arr)
            total += x;

        int left = 0;

        for(int i = 0; i < n; i++) {
            if(left == (total - left - arr[i])) {
                return i;
            }

            left += arr[i];
        }

        return -1;
    }
};
