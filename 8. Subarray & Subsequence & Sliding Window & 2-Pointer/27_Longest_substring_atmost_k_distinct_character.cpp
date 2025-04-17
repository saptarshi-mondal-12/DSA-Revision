#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Longest substring with atmost k distinct character

Given a string you need to print the size of the longest possible substring that has atmost K unique characters. If there is no possible substring then print -1.

Input: S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest substring with 3 distinct characters.


*/

int brute_longestSubstring(string s, int k){
    // Time complexity - O(n^2)
    // space complexity - O(k+1)

    // generate all substrings
    int n=s.size();
    int result=0;
    for(int i=0;i<n;i++){
        unordered_map<char, int>mp;
        for(int j=i;j<n;j++){
            mp[s[j]]++;
            if(mp.size() <= k){
                result=max(result, j-i+1);
            }else{
                break;
            }
        }
    }
    return result;
}

int better_longestSubstring(string s, int k){
    // Time complexity - O(n+n) = O(2n)
    // space complexity - O(k+1)

    // two pointer + sliding window
    int n=s.size();
    int result=0;
    unordered_map<char,int>mp;
    int left=0, right=0;
    while(right<n){
        mp[s[right]]++;
        while (mp.size() > k){
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

int optimal_longestSubstring(string s, int k){
    // Time complexity - O(n) 
    // space complexity - O(k+1)
    
    int n=s.size();
    int result=0;
    unordered_map<char,int>mp;
    int left=0, right=0;
    while(right<n){
        mp[s[right]]++;
        if (mp.size() > k){
            mp[s[left]]--;
            if(mp[s[left]] == 0){
                mp.erase(s[left]);
            }
            left++;
        }
        if(mp.size() <= k){
            result=max(result, right-left+1);
        }
        right++;
    }
    return result;
}

int main(){
    string s="aaaa";
    int k=2;

    // brute
    cout<<brute_longestSubstring(s,k)<<endl;

    // better
    cout<<better_longestSubstring(s,k)<<endl;

    // optimal
    cout<<optimal_longestSubstring(s,k)<<endl;
}