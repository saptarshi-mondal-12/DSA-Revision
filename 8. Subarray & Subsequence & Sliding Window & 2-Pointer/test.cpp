#include <iostream>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s){
    // Time complexity = O(n^2)
    // space complexity = O(3)

    // generate all substrings 
    int n=s.size();
    int result=0;
    for(int i=0;i<n;i++){
        set<char>st;
        for(int j=i;j<n;j++){
            st.insert(s[j]);
            if (st.size()==3){
                result+=1;
            }
        }
    }
    return result;
}

int better_numberOfSubstrings(string s){
    // Time complexity = O(n)
    // space complexity = O(1)

    int n=s.size();
    int result=0;
    int lastSeen[3]={-1,-1,-1};
    for(int i=0;i<n;i++){
        lastSeen[s[i]-'a']=i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            result=result + (1+min(lastSeen[0], lastSeen[1], lastSeen[2]));
        }
    }
    return result;
}

int main() {
    string s="bbacba"; // ans=9

    // brute
    // cout<<numberOfSubstrings(s)<<endl;

    // better
    cout<<better_numberOfSubstrings(s)<<endl;
}
