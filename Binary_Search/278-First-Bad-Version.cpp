// LeetCode 278 - First Bad Version
// Difficulty: Easy
// Topic: Binary Search
// Approach: Binary Search on Versions
//
// Problem:
// Given n versions where versions after a bad version are also bad,
// find the first bad version using the provided API.
//
// Approach Explanation:
// 1. Use binary search on the version numbers.
// 2. If mid is a bad version, the first bad version lies at mid
//    or before it, so move the right pointer to mid.
// 3. Otherwise, the first bad version must be after mid,
//    so move the left pointer to mid + 1.
// 4. When the search space shrinks to one element,
//    that element is the first bad version.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st=1;
        int end=n;
        while(st<end){
            int mid=st+(end-st)/2;
            if(isBadVersion(mid)){
                end=mid;
            }
            else{
                st=mid+1;
            }
        }
    return st;
    }
};
