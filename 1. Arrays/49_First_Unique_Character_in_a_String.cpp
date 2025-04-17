#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Given a string s, find the first non-repeating character in it and return its index. 
If it does not exist, return -1.

Input: s = "leetcode"
Output: 0
Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.

Input: s = "loveleetcode"
Output: 2

Input: s = "aabb"
Output: -1
*/

int brute_firstUniqChar(string s){
    // Time complexity = O(n^2)
    int n=s.size();
    int result=-1;
    for(int i=0;i<n;i++){
        bool check=true;
        for(int j=0;j<n;j++){
            if (s[i]==s[j] && i!=j){
                check=false;
                break;
            }
        }
        if(check){
            return i;
        }
    }
    return result;
}

int firstUniqChar(string s){
    // Time complexity = O(n) + O(n) = O(2n)
    // space complexity = O(no of distinct element)
    int n=s.size();
    int result=-1;
    unordered_map<char, int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    for(int i=0; i<n;i++){
        if(mp[s[i]]==1){
            result=i;
            break;
        }
    }
    return result;
}

int main(){
    string s="leetcode";

    // brute
    cout<<brute_firstUniqChar(s)<<endl;

    // optimal
    cout<<firstUniqChar(s)<<endl;
}