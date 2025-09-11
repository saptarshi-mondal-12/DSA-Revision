#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Longest Substring Without Repeating Characters - AMAZON 2 times

OR 

Longest Substring with All Distinct Characters

Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int brute_longestSubstring(string s){
    // Time complexity = O(n^2)
    // space complexity = O(n)

    // generate all substring
    int n=s.size();
    int result=0;
    for(int i=0;i<n;i++){
        int count=0;
        unordered_map<char, int>mp;
        for(int j=i;j<n;j++){
            mp[s[j]]++;
            count++;
            if(mp[s[j]] == 2){
                count--;
                break;
            }
        }
        result=max(result, count);
    }
    return result;
}

int better_longestSubstring(string s){
    // Time complexity = O(n)
    // space complexity = O(n)

    // two pointer sliding window
    int n = s.size();
    int result=0;

    unordered_map<char, int> mp;

    int left=0, right=0;
    while(right < n){
        char ch = s[right];
        mp[ch]++;

        while(mp[ch] > 1){
            mp[s[left]]--;
            if(mp[s[left]] == 0){
                mp.erase(s[left]);
            }
            left++;
        }

        result=max(result, right-left+1);
        right++;
    }
    return result;
}
int main(){
    string s="abcabcbb";

    // brute
    cout<<brute_longestSubstring(s)<<endl;

    // better
    cout<<better_longestSubstring(s)<<endl;


}