#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Substrings of length k with k-1 distinct elements

Given a String S consisting only lowercase alphabets and an integer K. Find the count of all substrings of length K which have exactly K-1 distinct characters.

Input: S = "abcc", K = 2
Output: 1
Explanation: Possible substrings of length K = 2 are
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct character
Only one valid substring exists {"cc"}. 

Input: S = "aabab", K = 3
Output : 3
Explanation: Possible substrings of length K = 3 are
aab : 2 distinct characters
aba : 2 distinct characters
bab : 2 distinct characters.
All of these Substrings are a possible answer, so the count is 3.
*/

int brute_countOfSubstrings(string s, int k){
    // Time Complexity: O(N*K)
    // Auxiliary Space: O(K)
    
    int n=s.size();
    int result=0;
        
    for(int i=0;i<n-k+1;i++){
        string s1=s.substr(i,k);
        unordered_map<char, int>mp;
        for(auto it: s1){
            mp[it]++;
        }
        if(mp.size()==k-1){
            result+=1;
        }
    }
    return result;
}

int optimal_countOfSubstrings(string s, int k){
    // Time Complexity: O(N)
    // Auxiliary Space: O(K)
    int n=s.size();
    int result=0;
    unordered_map<char,int>mp;
    for(int i=0;i<k;i++){
        mp[s[i]]++;
    }
        
    if(mp.size()==k-1){
        result+=1;
    }
        
    for(int i=k;i<n;i++){
        mp[s[i]]++;
        mp[s[i-k]]--;
            
        if (mp[s[i - k]] == 0) { 
            mp.erase(s[i - k]); 
        }
            
        if(mp.size()==k-1){
            result+=1;
        }
    }   
    return  result;
}

int main(){
    string s="abcc";
    int k=2;

    // brute
    cout<<brute_countOfSubstrings(s,k)<<endl;

    // optimal
    cout<<optimal_countOfSubstrings(s,k)<<endl;
}