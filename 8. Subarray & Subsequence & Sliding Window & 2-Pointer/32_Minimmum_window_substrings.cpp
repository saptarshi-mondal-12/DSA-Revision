#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Minimum window substrings

Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

string brute_minmumSubstring(string s, string t){
    // Time complexity - O(n^2)
    // space complexity - O(256)

    // generate all substrings
    int n=s.size();
    int m=t.size();
    long long int maxLen=INT_MAX;
    int startIndex=-1;
    string result="";
    for(int i=0;i<n;i++){
        int hash[256]={0};
        int count=0;

        // pre inserting the string t
        for(int j=0;j<m;j++){
            hash[t[j]-'a']++;
        }

        // generating all substring for i th index and checking
        for(int j=i;j<n;j++){
            if(hash[s[j]-'a'] > 0){
                count++;
            }
            hash[s[j]-'a']--;
            if(count==m){
                if(j-i+1 < maxLen){
                    maxLen=j-i+1;
                    startIndex=i;
                    break;
                }
            }  
        }
    }
    result=s.substr(startIndex, maxLen);
    return result;
}

string better_minmumSubstring(string s, string t){
    // Time complexity - O(m)+O(2n)
    // space complexity - O(256)
    int n=s.size();
    int m=t.size();
    string result="";
    int startIndex=-1;
    long long int maxLen=INT_MAX;
    int hash[256]={0};
    for(int i=0;i<m;i++){
        hash[t[i]]++;
    }
    int left=0, right=0;
    int count=0;
    while(right < n){
        if(hash[s[right]] > 0){
            count++;
        }
        hash[s[right]]--;

        while (count==m){
            if(right-left+1 < maxLen){
                maxLen=right-left+1;
                startIndex=left;
            }
            hash[s[left]]+=1;
            if(hash[s[left]] > 0){
                count--;
            }
            left++;
        }
        right++;
    }
    if(startIndex==-1){
        return "";
    }
    result=s.substr(startIndex, maxLen);
    return result;
}



int main(){
    string s="ddaaabbca";
    string t="abc";

    // brute
    cout<<brute_minmumSubstring(s,t)<<endl;

    // better
    cout<<better_minmumSubstring(s,t)<<endl;
}