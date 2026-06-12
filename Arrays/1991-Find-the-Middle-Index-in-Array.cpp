// LeetCode 1991 - Find the Middle Index in Array
// Difficulty: Easy
// Topic: Arrays, Prefix Sum
// Approach: Running Prefix Sum
//
// Problem:
// Find the leftmost middle index where the sum of elements
// to the left equals the sum of elements to the right.
//
// Approach Explanation:
// 1. Compute the total sum of the array.
// 2. Maintain a running left sum.
// 3. For each index, calculate:
//    Right Sum = Total Sum - Left Sum - Current Element
// 4. If left sum equals right sum, return the index.
// 5. If no such index exists, return -1.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int findMiddleIndex(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        if(n==1) return 0;
        for(int x : arr) total+=x;

        int left=0;
        for(int i=0;i<n;i++){
            
            if(left==(total-left-arr[i])){
                return i;
            
            }
            left+=arr[i];

        }
        return -1;

    }
};
