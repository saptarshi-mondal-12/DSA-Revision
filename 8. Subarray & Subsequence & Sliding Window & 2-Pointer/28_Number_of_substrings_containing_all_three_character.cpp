#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Number of substrings containing all three character

Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Input: s = "abc"
Output: 1
 
*/

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
    vector<int>lastSeen{-1,-1,-1};
    for(int i=0;i<n;i++){ 
        lastSeen[s[i]-'a']=i;
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            // left me kitna hai - *min_element(lastSeen.begin(), lastSeen.end());
            result=result + 1 + *min_element(lastSeen.begin(), lastSeen.end());
        }
    }
    return result;
}


int main(){
    string s="bbacba"; // ans=9

    // brute
    cout<<numberOfSubstrings(s)<<endl;

    // better
    cout<<better_numberOfSubstrings(s)<<endl;
}