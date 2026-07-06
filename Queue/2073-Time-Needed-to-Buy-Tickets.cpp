// LeetCode 2073 - Time Needed to Buy Tickets
// Difficulty: Easy
// Topic: Queue, Simulation, Array
// Approach: Count Turns Without Simulation
//
// Problem:
// There are people standing in a queue to buy tickets.
// Each person buys one ticket per turn and moves to the
// end of the queue if they still need more tickets.
// Find the total time until person k finishes buying tickets.
//
// Approach Explanation:
// 1. Person k buys exactly tickets[k] tickets.
// 2. Every person before or at index k can buy at most
//    tickets[k] tickets before person k finishes.
// 3. Every person after index k can buy at most
//    tickets[k] - 1 tickets because person k leaves the
//    queue immediately after purchasing the last ticket.
// 4. Sum these contributions to obtain the total time.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        
        for(int i=0;i<tickets.size();i++){
            if(i<=k){
                time+=min(tickets[k],tickets[i]);
            }
            else{
                time+=min(tickets[k]-1,tickets[i]);
            }
        }
        return time;
    }
};
