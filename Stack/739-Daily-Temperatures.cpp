// LeetCode 739 - Daily Temperatures
// Difficulty: Medium
// Topic: Stack, Monotonic Stack, Array
// Approach: Next Greater Element (Monotonic Stack)
//
// Problem:
// Given an array of daily temperatures, return an array
// where answer[i] is the number of days until a warmer
// temperature. If there is no future warmer day, answer[i] = 0.
//
// Approach Explanation:
// 1. Traverse the temperatures from right to left.
// 2. Maintain a monotonic decreasing stack of indices.
// 3. Remove all indices whose temperatures are less than
//    or equal to the current temperature.
// 4. If the stack is not empty, the top index represents
//    the next warmer day.
// 5. Store the distance between the two indices.
// 6. Push the current index onto the stack.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &vec){
        int n=vec.size();
        stack<int> st;
        vector<int> res(n);
        res[n-1]=0;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            if(!st.empty() && vec[st.top()]>vec[i]){
                res[i]=st.top();
            }
            else{
                while(!st.empty() && vec[st.top()]<=vec[i]){
                    st.pop();
                }
                if(st.empty()){
                    res[i]=0;
                }
                else{
                    res[i]=st.top();
                }
            }
            st.push(i);
        }
    return res;
    }
    vector<int> dailyTemperatures(vector<int>& temp) {
            int n=temp.size();
            vector<int> res=nextGreaterElement(temp);
            for(int i=0;i<n;i++){
                if(res[i]==0){
                    continue;
                }
                res[i]=res[i]-i;
            }
            return res;
    }
};
