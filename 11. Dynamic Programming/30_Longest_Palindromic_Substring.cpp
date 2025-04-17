#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Input: s = "cbbd"
Output: "bb"
*/


bool isPalindrome(string str){
    int i=0;
    int j=str.size()-1;
    while (i<j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string longestPalindrome1(string s) {
    // Time complexity: O(N^3)
    // Space complexity: O(1)
    int n=s.size();
    int maxi=0;
    string ans="";

    // Generating all substring 
    for(int i=0;i<n;i++){
        string str="";
        for(int j=i;j<n;j++){
            str+=s[j];
            if(isPalindrome(str) && (j-i+1) >= maxi){
                ans=str;
                maxi=j-i+1;
            }
        }
    }
    return ans;  
}


string longestPalindrome2(string s) {
    // Time complexity: O(N^2)
    // Space complexity: O(1)

    int n = s.size();
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        // Expand for odd-length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        // Expand for even-length palindromes
        left = i, right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    return s.substr(start, maxLen);
}

int main(){
    string s="babad";

    // brute
    cout<<longestPalindrome1(s)<<endl;

    // better
    cout<<longestPalindrome2(s)<<endl;

}