#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count Palindromic Substring

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

// Brute -> Generate all substrings and check for palindrome, if palindrome increase count
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
int countSubstrings1(string s) {
    // Time complexity: O(N^3) Because we have two for loops to iterate all possible substring and one loop to check if it is palindrome or not
    // Space complexity: O(1)

    int n=s.size();
    int count=0;

    // Generating all substring 
    for(int i=0;i<n;i++){
        string str="";
        for(int j=i;j<n;j++){
            str+=s[j];
            if(isPalindrome(str) ){
                count++;
            }
        }
    }
    return count;  
}


// better-> Expand-around-center technique-----------------------------------------------
int countSubstrings2(string s) {
    // Time complexity: O(n²) 
    // Space complexity: O(1) 
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        // Odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        // Even length palindromes
        left = i, right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }

    return count;
}


int main(){
    string s="aaa";

    // brute
    cout<<countSubstrings1(s)<<endl;

    // better
    cout<<countSubstrings2(s)<<endl;

}