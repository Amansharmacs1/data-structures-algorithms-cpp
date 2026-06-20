// LeetCode 560 - Subarray Sum Equals K
// Difficulty: Medium
// Topic: Arrays, Prefix Sum, Hash Map
// Approach: Prefix Sum + Hash Map
//
// Problem:
// Given an integer array nums and an integer k,
// return the total number of continuous subarrays
// whose sum equals k.
//
// Approach Explanation:
// 1. Compute the running prefix sum while traversing the array.
// 2. Store the frequency of each prefix sum in a hash map.
// 3. For each prefix sum, check if (prefixSum - k)
//    has been seen before.
// 4. If yes, add its frequency to the answer.
// 5. Update the frequency of the current prefix sum.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int count=0;
        unordered_map<int,int> mp;
        vector <int> res(n,0);
        res[0]=arr[0];
       for(int i=1;i<n;i++){
        res[i]=arr[i]+res[i-1];
       }
        for(int i=0;i<n;i++){
            if(res[i]==k) count++;
            if(mp.find(res[i]-k)!=mp.end()){
                count+=mp[res[i]-k];
            }
            mp[res[i]]++;
        }
        return count;
    }
};
