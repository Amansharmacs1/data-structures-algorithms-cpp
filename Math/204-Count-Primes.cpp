// LeetCode 204 - Count Primes
// Difficulty: Medium
// Topic: Math, Sieve of Eratosthenes
// Approach: Sieve Algorithm
//
// Problem:
// Given an integer n, return the number of prime numbers less than n.
//
// Approach Explanation:
// We use the Sieve of Eratosthenes:
// 1. Assume all numbers are prime initially
// 2. Start from 2, and mark its multiples as non-prime
// 3. Repeat for all numbers up to n
//
// Time Complexity: O(n log log n)
// Space Complexity: O(n)

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> isPrime(n + 1, true);

        for(int i = 2; i < n; i++){
            if(isPrime[i]){
                count++;

                for(int j = i * 2; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }

        return count;
    }
};
