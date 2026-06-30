 // LeetCode 4 - Median of Two Sorted Arrays
// Difficulty: Hard
// Topic: Binary Search, Array
// Approach: Binary Search on Partition
//
// Problem:
// Given two sorted arrays, find the median of the combined
// sorted array in O(log(min(m, n))) time.
//
// Approach Explanation:
// 1. Always perform binary search on the smaller array.
// 2. Partition both arrays such that the left half contains
//    (m + n + 1) / 2 elements.
// 3. Check if the partition is valid:
//      max(left1, left2) <= min(right1, right2)
// 4. If valid:
//      - For odd total length, median is the maximum element
//        of the left partition.
//      - For even total length, median is the average of the
//        maximum left and minimum right elements.
// 5. If left1 > right2, move the partition left.
// 6. Otherwise, move the partition right.
//
// Time Complexity: O(log(min(m, n)))
// Space Complexity: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int m=nums1.size();
        int n=nums2.size();

        int l=0;
        int r=m;
        while(l <= r){
            int px=l+(r-l)/2;
            int py=(m+n+1)/2 - px;

            int x1=(px==0 ? INT_MIN : nums1[px-1]);
            int x2=(py==0 ? INT_MIN : nums2[py-1]);

            int x3=(px==m ? INT_MAX : nums1[px]);
            int x4=(py==n ? INT_MAX : nums2[py]);

            if(x1<=x4 && x2<=x3){
                if((m+n)%2==1){
                    return max(x1,x2);
                }
                else{
                    return (max(x1,x2)+min(x3,x4))/2.0;
                }
            }
            if(x1>x4){
                r=px-1;
            }
            else{
                l=px+1;
            }
        }
        return -1;
    }
};
