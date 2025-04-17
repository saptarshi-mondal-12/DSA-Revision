#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Count Substrings That Satisfy K-Constraint. You are given a binary string s and an integer k.
A binary string satisfies the k-constraint if either of the following conditions holds:
The number of 0's in the string is at most k.
The number of 1's in the string is at most k.
Return an integer denoting the number of substrings of s that satisfy the k-constraint.

Input: s = "10101", k = 1
Output: 12
Explanation: Every substring of s except the substrings "1010", "10101", and "0101" satisfies the k-constraint.


Input: s = "1010101", k = 2
Output: 25
Explanation: Every substring of s except the substrings with a length greater than 5 satisfies the k-constraint.


Input: s = "11111", k = 1
Output: 15
Explanation: All substrings of s satisfy the k-constraint.
*/

int brute_countKConstraintSubstrings(string s, int k){
    // Time complexity - O(n^2)
    // space complexity - O(1)
    int n=s.size();
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int one=0, zero=0;
            for(int k=i;k<=j;k++){
                if(s[k]=='1'){
                    one++;
                }else{
                    zero++;
                }
            }
            if(one <= k || zero <= k){
                result+=1;
            }
        }
    }
    return result;
}

int optimal_countKConstraintSubstrings(string s, int k){
    // Time complexity - O(n)
    // space complexity - O(1)
    int n=s.size();
    int result=0;
    int left=0, right=0, one=0, zero=0;
    while(right < n){
        if(s[right] == '0'){
            zero++;
        }else{
            one++;
        }
        while (zero>k && one>k){
            if(s[left]=='1'){
                one-=1;
            }else{
                zero-=1;
            }
            left++;
        }
        result+=(right-left+1);
        right+=1;
    }
    return result;
}



int main(){
    string s="11111";
    int k=1;
    cout<<brute_countKConstraintSubstrings(s,k)<<endl;
    cout<<optimal_countKConstraintSubstrings(s,k);
}