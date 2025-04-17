#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Smallest Subsequence of Distinct Characters

Given a string s, return the lexicographically smallest subsequence of s that 
contains all the distinct characters of s exactly once.

Input: s = "bcabc"
Output: "abc"

Input: s = "cbacdcbc"
Output: "acdb"

--------------------------------------------------------OR--------------------------------------------------------- 

Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order among all possible results.

*/

void smallestSubsequence(string s){
    int hash[26]={0};
    int n=s.size();
    for(int i=0;i<n;i++){
        hash[s[i]-'a']=i;
    }
    stack<char>st;
    vector<bool> seen(26, false);
    for(int i=0;i<n;i++){
        int curr=s[i]-'a';
        if(seen[curr]){
            continue;
        }
        while(st.size()!=0 && st.top() > s[i] && hash[st.top()-'a'] > i ){
            seen[st.top()-'a']=false;
            st.pop();

        }
        st.push(s[i]);
        seen[curr]=true;
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}


int main(){
    string s="cbacdcbc";
    smallestSubsequence(s);
}