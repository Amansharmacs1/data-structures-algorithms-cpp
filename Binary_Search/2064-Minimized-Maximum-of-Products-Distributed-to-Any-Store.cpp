// LeetCode 2064 - Minimized Maximum of Products Distributed to Any Store
// Difficulty: Medium
// Topic: Binary Search, Greedy
// Approach: Binary Search on the Answer
//
// Problem:
// Distribute products among n stores such that each store receives
// only one product type and the maximum number of products assigned
// to any store is minimized.
//
// Approach Explanation:
// 1. The answer lies between 1 and the maximum quantity.
// 2. Binary search on the possible maximum products per store (mid).
// 3. For each product quantity, compute the number of stores needed:
//      stores = ceil(quantity / mid)
//             = (quantity + mid - 1) / mid
// 4. If the total required stores <= n, the distribution is possible.
//    Try a smaller maximum.
// 5. Otherwise, increase the allowed maximum.
//
// Time Complexity: O(m log M)
//   m = number of product types
//   M = maximum quantity
// Space Complexity: O(1)

class Solution {
public:
    bool isPossible(int n, vector<int>& quantities,int mid){
        int shop=0;
        for(auto stock : quantities){
            shop+=(stock+mid-1)/mid;
        }
        if(shop<=n){
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int st=1;
        int end=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(st<=end){
            int mid=st+(end-st)/2;
        
            if(isPossible(n,quantities,mid)){
                ans=mid;
                end=mid-1;

            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};
