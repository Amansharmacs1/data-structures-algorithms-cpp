// LeetCode 496 - Next Greater Element I
// Difficulty: Easy
// Topic: Stack, Monotonic Stack, HashMap
// Approach: Monotonic decreasing stack from right to left + preprocessing
//
// Problem:
// For each element in nums1, find the next greater element in nums2.
// If it does not exist, return -1.
//
// Approach Explanation:
// - Use a monotonic decreasing stack to process nums2 from right to left.
// - Maintain a map that stores the next greater element for each number in nums2.
// - For each element:
//   - Pop smaller or equal elements from stack.
//   - Top of stack is next greater element (if exists).
//   - If stack is empty, answer is -1.
// - Finally, map results for nums1.
//
// Time Complexity: O(N + M)
// Space Complexity: O(N)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> m;
        stack<int> s;

        for(int i = arr2.size() - 1; i >= 0; i--) {

            while(!s.empty() && s.top() <= arr2[i]) {
                s.pop();
            }

            if(s.empty()) {
                m[arr2[i]] = -1;
            } 
            else {
                m[arr2[i]] = s.top();
            }

            s.push(arr2[i]);
        }

        vector<int> ans;

        for(int i = 0; i < arr1.size(); i++) {
            ans.push_back(m[arr1[i]]);
        }

        return ans;
    }
};
