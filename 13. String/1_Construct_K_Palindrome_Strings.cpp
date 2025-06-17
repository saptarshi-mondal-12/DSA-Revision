#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <string>

/* Q. Construct K Palindrome Strings - AMAZON

Given a string s and an integer k, return true if you can use all the characters in s to construct non-empty k palindrome strings or false otherwise.

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.*/

bool canConstruct(string s, int k) {
    // Time complexity: O(n)
    // Space complexity: O(26)

    int n = s.size();

    // If k is greater than the length of s, it's impossible to form k palindromic strings
    if (k > n) return false;

    // Create a frequency map to count the occurrences of each character
    unordered_map<char, int> freq;
    for (int i = 0; i < n; i++) {
        freq[s[i]]++;
    }

    // Count the number of characters that appear an odd number of times
    int oddCount = 0;
    for (auto it : freq) {
        oddCount += (it.second % 2);
    }

    // To form k palindromic strings, we must have at least 'oddCount' palindromes
    // If oddCount > k, it's impossible to construct the palindromes
    if (oddCount > k) {
        return false;
    }
    
    // Otherwise, it is possible
    return true;
}

int main(){
    string s = "annabelle";
    int k=2;
    
    cout<<canConstruct(s,k)<<endl;
}