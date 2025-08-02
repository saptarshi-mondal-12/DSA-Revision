#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. AMAZON 2025  

Determine the sequence after removing the redundant nodes with similar configuration. Maintain the dependency order. Choose the lexicographically larger sequence, incase of multiple possible sequences.

Input: AZADA
Output: ZDA

Input: AZAD
Output: ZAD

Input: ZAZDA
Output: ZDA

*/


string solve(string s){
    int n=s.size();

    // Frequency count of each character
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }

    

    // check for duplicates characters
    unordered_set<char>contains;

    // Using stack for lexicographically larger one.
    stack<char>st;

    for(int i=0;i<n;i++){
        char ch=s[i];

        if(contains.count(ch)){
            mp[ch]--; // we process current character so reduce its frequency
            continue;
        }

        while(!st.empty() && st.top() < ch && mp[st.top()]>1){
            contains.erase(st.top());
            mp[st.top()]--;
            st.pop();
        }

        st.push(ch);
        contains.insert(ch);
    }

    // Extract answer from stack
    string ans;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    // reverse the answer
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s="ZSZDA"; // ZSDA
    // string s = "BCAC"; // BCA
    // string s = "AZADA"; // ZDA
    // string s = "AZAD"; // ZAD
    // string s = "AAAAA"; // A
    // string s = "ZYX"; // ZYX
    // string s = "ABC"; // ABC
    // string s = "AZAZAZ"; // ZA
    // string s = "AZAZBZC"; // ZABC
    // string s = "BACDABC"; // DABC
    // string s = "ABCDEZ"; // ABCDEZ
    // string s = "ACBACBACD"; // CBAD
    // string s = ""; // ""
    
   cout<<solve(s);
}