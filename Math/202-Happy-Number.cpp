// LeetCode 202 - Happy Number
// Difficulty: Easy
// Topic: Math, Hash Table, Two Pointers
// Approach: Floyd's Cycle Detection
//
// Problem:
// A happy number is defined by repeatedly replacing the number
// with the sum of the squares of its digits until it becomes 1.
// Return true if the number is happy, otherwise false.
//
// Approach Explanation:
// 1. Create a function to compute the sum of the squares of digits.
// 2. Use Floyd's Cycle Detection algorithm:
//    - Slow pointer moves one step.
//    - Fast pointer moves two steps.
// 3. If the fast pointer reaches 1, the number is happy.
// 4. If slow and fast meet at a value other than 1,
//    a cycle exists, so the number is not happy.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int sumOfSquaredDigitsOfNum(int n){
        int sum=0;
        while(n!=0){
            int digit=n%10;
            n=n/10;
            sum+=(digit*digit);
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(true){
            slow=sumOfSquaredDigitsOfNum(slow);
            fast=sumOfSquaredDigitsOfNum(sumOfSquaredDigitsOfNum(fast));

            if(fast==1){
                return true;
            }
            if(slow==fast){
                return false;
            }
        }
    }
};
