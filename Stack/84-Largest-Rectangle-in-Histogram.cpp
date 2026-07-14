// LeetCode 84 - Largest Rectangle in Histogram
// Difficulty: Hard
// Topic: Stack, Monotonic Stack
// Approach: Previous & Next Smaller Element
//
// Problem:
// Given an array representing the heights of histogram bars,
// find the area of the largest rectangle that can be formed.
//
// Approach Explanation:
// 1. Find the Previous Smaller Element (PSE) for every bar.
//    It gives the nearest smaller bar on the left.
// 2. Find the Next Smaller Element (NSE) for every bar.
//    It gives the nearest smaller bar on the right.
// 3. For each bar:
//      Width = NSE - PSE - 1
//      Area  = Height × Width
// 4. Return the maximum area among all bars.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:

//Next Smaller Element
vector<inxt> NextSmallerElement(vector<int> vec){
    int n=vec.size();
    vector<int> res(n);
    stack<int> st;
     
    st.push(n-1);
    res[n-1]=-1;
    
    for(int i=n-2;i>=0;i--){
        if(!st.empty() && vec[st.top()]<vec[i]){
            res[i]=st.top();
        }
        else{
            while(!st.empty() && vec[st.top()]>=vec[i]){
                st.pop();
            }
            if(!st.empty()){
               res[i]=st.top(); 
            }
            else{
                res[i]=-1;
            }
        }
        st.push(i);
    }
    return res;
}

//Prev Smaller Element
vector<int> PrevSmallerElement(vector<int> vec){
    int n=vec.size();
    vector<int> res(n);
    stack<int> st;
    
    st.push(0);
    res[0]=-1;
    
    for(int i=1;i<n;i++){
        if(!st.empty() && vec[st.top()]<vec[i]){
            res[i]=st.top();
        }
        else{
            while(!st.empty() && vec[st.top()]>=vec[i]){
                st.pop();
            }
            if(!st.empty()){
               res[i]=st.top(); 
            }
            else{
                res[i]=-1;
            }
        }
        st.push(i);
    }
    return res;
}

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next=NextSmallerElement(heights);
        vector<int> prev=PrevSmallerElement(heights);

        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){

            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int w=next[i]-prev[i]-1;
            int area=l*w;
            maxArea=max(maxArea,area);

        }
        return maxArea;
    }
};
