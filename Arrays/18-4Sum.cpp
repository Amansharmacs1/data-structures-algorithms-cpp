// LeetCode 18 - 4Sum
// Difficulty: Medium
// Topic: Arrays, Sorting, Two Pointers
// Approach: Sorting + Nested Loops + Two Pointers
//
// Problem:
// Find all unique quadruplets [a, b, c, d]
// such that:
//
// a + b + c + d = target
//
// Approach Explanation:
// 1. Sort the array.
// 2. Fix the first two elements using nested loops.
// 3. Use two pointers for the remaining two elements.
// 4. Compare the current sum with the target.
// 5. Skip duplicates to ensure unique quadruplets.
// 6. Store all valid quadruplets.
//
// Time Complexity: O(n³)
// Space Complexity: O(1) (excluding output)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int tar) {
          vector <vector<int>> ans;
    
    int n=arr.size();
    
    sort(arr.begin(),arr.end());
    
    for(int i=0;i<n-3;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        
        for(int j=i+1;j<n;j++){
           int p=j+1,q=n-1;
           
            while(p<q){
               long long sum=(long long)arr[i]+(long long)arr[j]+(long long)arr[p]+(long long)arr[q];
               
               if(sum<tar){
                   p++;
               }
               else if(sum>tar){
                   q--;
               }
               else{
                   ans.push_back({arr[i],arr[j],arr[p],arr[q]});
                   p++;
                   q--;

                   while(p<q && arr[p]==arr[p-1]) p++; 
               }
            }
        
            while(j<n-1 && arr[j]==arr[j-1]) j++;
        }
    }
    return ans;
    }
};
