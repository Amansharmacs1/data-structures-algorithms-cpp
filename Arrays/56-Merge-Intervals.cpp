// LeetCode 56 - Merge Intervals
// Difficulty: Medium
// Topic: Arrays, Sorting
// Approach: Sort + Merge
//
// Problem:
// Given an array of intervals where intervals[i] = [start, end],
// merge all overlapping intervals and return the resulting array.
//
// Approach Explanation:
// 1. Sort the intervals based on their starting values.
// 2. Traverse the sorted intervals.
// 3. If the current interval does not overlap with the last merged interval,
//    add it to the result.
// 4. Otherwise, merge the intervals by updating the end value.
// 5. Return the merged list of intervals.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(res.empty() || res.back()[1]<intervals[i][0]){
                res.push_back(intervals[i]);
            }
            else{
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }


        return res;
    }
};
