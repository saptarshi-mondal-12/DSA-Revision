#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Substring with At Least K Repeating Characters

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.*/

int solve1(string s, int k) {
    if(s.size() == 0 || k > s.size())   return 0;
    if(k == 0)  return s.size();
    
    unordered_map<char,int> Map;
    for(int i = 0; i < s.size(); i++){
        Map[s[i]]++;
    }
    
    int idx=0;
    while(idx <s.size() && Map[s[idx]] >= k){
        idx++;
    }
    if(idx == s.size()) return s.size();
    
    int left = solve1(s.substr(0 , idx) , k);
    int right = solve1(s.substr(idx+1) , k);
    
    return max(left, right);
}
int longestSubstring(string s, int k) {
    // Time complexity: O(n^2)
    // Space complexity: O(n) recursive stack space

    int n = s.size();
    return solve1(s, k);
}

int main(){
    string s="aaabb";
    int k=3;
    cout<<longestSubstring(s,k)<<endl;

    // Hint: We can optimize using memoization
}