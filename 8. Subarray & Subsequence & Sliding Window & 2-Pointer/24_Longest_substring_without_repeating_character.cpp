#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Longest Substring Without Repeating Characters

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
    int n=s.size();
    int result=0;
    int left=0;
    int right=0;
    unordered_map<char, int>mp;
    while (right < n){
        if (mp.find(s[right])!=mp.end()){
            // it is present in the map

            if (left <= mp[s[right]]){
                left=mp[s[right]]+1;
                mp[s[right]]=right;
            }
        }

        mp[s[right]]=right;
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