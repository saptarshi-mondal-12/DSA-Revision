#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q.  Count Substrings Starting and Ending with Given Character

You are given a string s and a character c. Return the total number of substrings of s that start and end with c.

Input: s = "abada", c = "a"
Output: 6
Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".

Input: s = "zzz", c = "z"
Output: 6
Explanation: There are a total of 6 substrings in s and all start and end with "z".

Intuition: 
Hint: Start count from last, 1 current and prev for previous substring
For e.g zzz, prev=0
    z prev = 1+prev = 1
    zz = prev = 1+prev = 2
    zzz = prev = 1+2 = 3
    Toal = 3+2+1=6
*/

long long countSubstrings(string s, char c) {
    // Time complexity: O(n)
    // Space complexity: O(1)

    int n=s.size();
    long long result=0;
    int prev=0; 
    for(int i=n-1;i>=0;i--){
        if (s[i] == c){
            result+=1+prev;
            prev+=1;
        }
    } 
    return result; 


    

    // c=s.count(c)
    // return c*(c+1)//2
}

int main(){
    string s="zzz";
    char c='z';
    cout<<countSubstrings(s, c)<<endl;
}