#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

/* Q. Longest Palindrome by Concatenating Two Letter Words

NOTE : TRY IT BEFORE SEEING SOLUTION IN GOOGLE DOCS WITH EXPALNATION 
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-25

You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.



Example 1:
Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".*/

int longestPalindrome(vector<string> &words){
    //  Time Complexity: O(n)
    // Total Space Complexity: O(1) because At most 676 distinct 2-letter lowercase combinations.

    unordered_map<string, int> mp;
    int ans = 0;
    int center = 0; // to check if we can put one palindromic word in center

    for (const string &word : words){
        string rev = word;
        reverse(rev.begin(), rev.end());

        if (mp[rev] > 0){
            ans += 4;
            mp[rev]--;
        }
        else{
            mp[word]++;
        }
    }

    // check for any leftover palindromic pair like "gg"
    for (auto it : mp){
        if (it.first[0] == it.first[1] && it.second > 0)
        {
            center = 2;
            break;
        }
    }

    return ans + center;
}