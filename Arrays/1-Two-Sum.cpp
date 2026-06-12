// LeetCode 1 - Two Sum
// Difficulty: Easy
// Topic: Arrays, Sorting, Two Pointers
// Approach: Sort + Two Pointers
//
// Problem:
// Find two numbers in the array whose sum equals the target
// and return their original indices.
//
// Approach Explanation:
// 1. Store each element along with its original index.
// 2. Sort the array of {value, index} pairs.
// 3. Use two pointers from both ends.
// 4. If current sum equals target, return original indices.
// 5. If sum is smaller, move left pointer.
// 6. If sum is larger, move right pointer.
//
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int,int>>vp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vp.push_back({nums[i],i});
        }

        sort(vp.begin(),vp.end());

        int left=0,right=n-1;

        while(left<right){
            int sum=vp[left].first + vp[right].first;
            if(sum==target){
                return {vp[left].second,vp[right].second};
            }
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};
