#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Count Substrings With K-Frequency Characters I

Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.

Input: s = "abacb", k = 2
Output: 4
Explanation: The valid substrings are:
"aba" (character 'a' appears 2 times).
"abac" (character 'a' appears 2 times).
"abacb" (character 'a' appears 2 times).
"bacb" (character 'b' appears 2 times).

Input: s = "abcde", k = 1
Output: 15
Explanation: All substrings are valid because every character appears at least once.
*/

int brute_numberOfSubstrings(string s, int k){
    // TC = O(N^2)

    int result=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        int hash[26]={0};
        int maxi=0;
        for(int j=i;j<n;j++){
            char ch=s[j];
            hash[ch - 'a']++;
            maxi=max(maxi, hash[ch-'a']);
            if (maxi >= k){
                result+=(n-j);
                break;
            }
        }
    }
    return result;
}

int optimal_numberOfSubstrings(string s, int k){
    int n=s.size();
    int result=0;
    int left=0, right=0;
    unordered_map<char,int>mp;
    while(right < n){
        char ch=s[right];
        mp[ch]++;
        while(mp[ch] >= k){
            result+=(n-right);
            mp[s[left]]--;
            left++;
        }
        right++;
    }
    return result;
}

int main(){
    string s="abacb";
    int k=2;

    // brute
    cout<<brute_numberOfSubstrings(s,k)<<endl;

    // optimal
    cout<<optimal_numberOfSubstrings(s,k)<<endl;
}