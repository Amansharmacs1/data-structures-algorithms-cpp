// LeetCode 1925 - Count Square Sum Triples
// Difficulty: Easy
// Topic: Math, Brute Force
// Approach: Enumeration
//
// Problem:
// Given an integer n, return the number of triples (a, b, c)
// such that:
// 1 <= a, b, c <= n
// and a^2 + b^2 = c^2
//
// Approach Explanation:
// We try all possible pairs (a, b):
// 1. Compute a^2 + b^2
// 2. Take square root → c
// 3. Check if c is integer and <= n
//
// If valid → increment count
//
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int countTriples(int n) {
        int count = 0;

        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                int res = a*a + b*b;
                int c = sqrt(res);

                if(c <= n && c*c == res){
                    count++;
                }
            }
        }

        return count;
    }
};
