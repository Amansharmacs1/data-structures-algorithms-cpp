// LeetCode 503 - Next Greater Element II
// Difficulty: Medium
// Topic: Stack, Monotonic Stack, Circular Array
// Approach: Monotonic decreasing stack with circular traversal (2n-1 to 0)
//
// Problem:
// Given a circular array, find the next greater element for each element.
// If it does not exist, return -1.
//
// Approach Explanation:
// - Treat array as circular by iterating from 2*n - 1 to 0.
// - Use a monotonic decreasing stack storing indices.
// - For each index i:
//   - Pop all elements smaller or equal to current element.
//   - If stack is empty → no greater element (-1)
//   - Else top of stack gives next greater element.
// - Use modulo (i % n) to simulate circular behavior.
//
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n, 0);

        for(int i = 2 * n - 1; i >= 0; i--) {

            while(!s.empty() && arr[s.top()] <= arr[i % n]) {
                s.pop();
            }

            ans[i % n] = s.empty() ? -1 : arr[s.top()];

            s.push(i % n);
        }

        return ans;
    }
};
