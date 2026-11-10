/* Q. Group Anagrams - AMAZON 2026

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Input: strs = [""]
Output: [[""]]

Input: strs = ["a"]
Output: [["a"]]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Time Complexity: O(n * klogk)
        // Space Complexity: O(n * k)

        int n = strs.size();
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        for(auto it: strs){
            string key = it;
            sort(key.begin(), key.end());
            mp[key].push_back(it);
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};