// LeetCode 387 - First Unique Character in a String
// Difficulty: Easy
// Topic: Queue, Hash Table, String
// Approach: Queue + Frequency Map
//
// Problem:
// Given a string, find the index of the first non-repeating
// character. Return -1 if none exists.
//
// Approach Explanation:
// 1. Traverse the string from left to right.
// 2. Maintain a frequency map for each character.
// 3. If a character appears for the first time,
//    push its index into a queue.
// 4. Remove indices from the front of the queue while
//    their characters have frequency greater than 1.
// 5. After processing the string, the front of the queue
//    (if any) is the first unique character.
//
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        queue<int> q;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                q.push(i);
            }

            mp[s[i]]++;
            while(q.size()>0 && mp[s[q.front()]]>1){
                q.pop();
            }
            }
            
        return q.empty()? -1: q.front();
    }
};
