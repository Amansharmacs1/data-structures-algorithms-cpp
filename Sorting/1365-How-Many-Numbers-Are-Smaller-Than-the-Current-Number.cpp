// LeetCode 1365 - How Many Numbers Are Smaller Than the Current Number
// Difficulty: Easy
// Topic: Sorting, Hash Table, Array
// Approach: Sort + First Occurrence Mapping
//
// Problem:
// Given an array nums, return an array where answer[i]
// is the number of elements smaller than nums[i].
//
// Approach Explanation:
// 1. Make a copy of the original array and sort it.
// 2. Store the first occurrence index of every distinct
//    number in a hash map.
// 3. Since the array is sorted, the first occurrence index
//    equals the number of elements smaller than that value.
// 4. Traverse the original array and replace each element
//    with its mapped index.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());

        for(int i=0;i<sorted.size();i++){
            if(m.find(sorted[i])==m.end()){
                m[sorted[i]]=i;
            }
        }
        vector<int> res;
        for( int i=0;i<n;i++){
            res.push_back(m[nums[i]]);
        }
    return res;

    }
};
