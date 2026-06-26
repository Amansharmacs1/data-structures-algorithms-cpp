// LeetCode 49 - Group Anagrams
// Difficulty: Medium
// Topic: Strings, Hash Table, Sorting
// Approach: Sort Characters + Hash Map
//
// Problem:
// Given an array of strings, group the anagrams together.
//
// Approach Explanation:
// 1. Traverse each string in the array.
// 2. Create a copy of the string and sort its characters.
// 3. Use the sorted string as the key in a hash map.
// 4. Strings with the same sorted key are anagrams and
//    are grouped together.
// 5. Collect all groups from the hash map and return them.
//
// Time Complexity: O(n * k log k)
//   n = number of strings
//   k = average length of a string
// Space Complexity: O(n * k)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto val :strs){
            string key=val;
            sort(key.begin(),key.end());
            mp[key].push_back(val);
        }
        vector<vector<string>> ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }

};
