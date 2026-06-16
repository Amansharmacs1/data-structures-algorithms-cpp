// LeetCode 88 - Merge Sorted Array
// Difficulty: Easy
// Topic: Arrays, Two Pointers
// Approach: Three Pointers (Backward Merge)
//
// Problem:
// Merge two sorted arrays into nums1 as one sorted array.
//
// Approach Explanation:
// 1. Start from the end of both arrays.
// 2. Compare the largest remaining elements.
// 3. Place the larger element at the end of nums1.
// 4. Move pointers accordingly.
// 5. If elements remain in nums2, copy them into nums1.
//
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    void merge(vector<int>& vec1, int m, vector<int>& vec2, int n) {
          int i=m-1;
          int j=n-1;
          int idx=m+n-1;
          while(i>=0 && j>=0){
            if(vec1[i]<vec2[j]){
                vec1[idx]=vec2[j];
                j--;
                idx--;
            }
            else{
                vec1[idx]=vec1[i];
                i--;
                idx--;
            }
          }
          while(j>=0){
            vec1[idx]=vec2[j];
            idx--;
            j--;
          }
    }
};
