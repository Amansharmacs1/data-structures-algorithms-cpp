// LeetCode 134 - Gas Station
// Difficulty: Medium
// Topic: Greedy
// Approach: Greedy with Running Balance
//
// Problem:
// There are n gas stations arranged in a circle. At station i,
// you gain gas[i] liters and need cost[i] liters to travel to
// the next station. Return the starting station's index if you
// can complete the circuit exactly once; otherwise, return -1.
//
// Approach Explanation:
// 1. Compute the total gas and total cost.
//    - If totalGas < totalCost, completing the circuit is
//      impossible, so return -1.
// 2. Traverse all stations while maintaining the current
//    gas balance (currGas).
// 3. If currGas becomes negative at station i, then no station
//    from the current start to i can be a valid starting point.
//    Therefore, set the next station (i + 1) as the new start
//    and reset currGas to 0.
// 4. After one traversal, if totalGas >= totalCost, the stored
//    starting index is the answer.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int totalCost=0;
        
        int start=0;
        int currGas=0;

        for(int i=0;i<gas.size();i++){

            totalGas+=gas[i];
            totalCost+=cost[i];

            currGas+=(gas[i]-cost[i]);
            if(currGas<0){
                start=i+1;
                currGas=0;
            }

        }
        return totalGas<totalCost? -1 : start;
    }
};
