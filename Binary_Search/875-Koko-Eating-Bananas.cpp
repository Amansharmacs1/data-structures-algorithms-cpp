// LeetCode 875 - Koko Eating Bananas
// Difficulty: Medium
// Topic: Binary Search
// Approach: Binary Search on the Answer
//
// Problem:
// Koko wants to eat all the bananas within h hours.
// Find the minimum eating speed (bananas/hour) required.
//
// Approach Explanation:
// 1. The minimum possible eating speed is 1 banana/hour.
// 2. The maximum possible eating speed is the largest pile.
// 3. Use binary search on the eating speed.
// 4. For a given speed (mid), calculate the total hours needed:
//      hours += ceil(pile / mid)
//             = (pile + mid - 1) / mid
// 5. If the total hours are within h, try a smaller speed.
// 6. Otherwise, increase the eating speed.
//
// Time Complexity: O(n log M)
//   n = number of piles
//   M = maximum pile size
// Space Complexity: O(1)


class Solution {
public:
    bool isPossible(vector<int>& piles, int h,int mid){
        long long int total=0;
        for(auto p : piles){
            total+=(p+mid-1)/mid;
        }
        if(total<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1;
        int end=*max_element(piles.begin(),piles.end());
        int ans=0;
    
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isPossible(piles,h,mid)){
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
