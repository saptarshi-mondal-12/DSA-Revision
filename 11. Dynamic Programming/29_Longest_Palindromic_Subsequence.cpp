#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Palindromic Subsequence + Print

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

-------Intuition: 
We are given a string S, the simplest approach will be to generate all the subsequences and store them, then manually find out the longest palindromic subsequence.

This naive approach will give us the correct answer but to generate all the subsequences, we will require exponential ( 2n ) time. Therefore we will try some other approaches.

Using Dynamic Programming

Let us say that we are given the following string.
s1 = "bbabcbcab"

The longest palindromic subsequence will be: “babcbab”.

What is special about this string is that it is palindromic (equal to its reverse) and of the longest length.

Now let us write the reverse of s1 next to it and please think about the highlighted characters.

s1                = "bbabcbcab"
                     - ---- --
s2(reverse of s1) = "bacbcbabb"
                     -- -----

The longest palindromic subsequence will be: “babcbab”.

If we look closely at the highlighted characters, they are nothing but the longest common subsequence of the two strings.

Now, we have taken the reverse of the string for the following two reasons:

The longest palindromic subsequence being a palindrome will remain the same when the entire string is reversed. The length of the palindromic subsequence will also remain the same when the entire string is reversed. From the above discussion we can conclude:

Ans: The longest palindromic subsequence of a string is the longest common subsequence of the given string and its reverse.

Approach:
1. We are given a string (say s), make a copy of it and store it( say string t).
2. Reverse the original string s.
3. Find the longest common subsequence as discussed in dp-25.

NOTE: Print same as (print LCS) question
*/


// Tabulation----------------------------------------------------------
int longestPalindromeSubseq1(string s1) {
    // Time complexity: O(N*N)
    // Space complexity: O(N*N)

    int n = s1.size();

    // Create a reversed copy of the string s1
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int m = s2.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                int move_i = 0 + dp[i - 1][j];
                int move_j = 0 + dp[i][j - 1];
                dp[i][j] = max(move_i, move_j);
            }
        }
    }

    // Follow up question -> Print the string of Longest Palindromic Subsequence

    int length = dp[n][m];
    string ans="";
    int index = length-1;
    for(int i=0;i<length;i++){
        ans+="$"; // dummy string
    }

    int i=n;
    int j=m;

    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    cout<<"Longest Palindromic Subsequence: "<<ans<<endl;
    return dp[n][m];
}



// Space optimization--------------------------------------------------
int longestPalindromeSubseq2(string s1) {
    // Time complexity: O(N*N)
    // Space complexity: O(N)

    int n = s1.size();

    // Create a reversed copy of the string s1
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int m = s2.size();

    vector<int>prev(m+1, 0);

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        prev[0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        prev[j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        vector<int>curr(m+1, 0);
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1]) {
                curr[j] = 1 + prev[j - 1];
            }
            else {
                int move_i = 0 + prev[j];
                int move_j = 0 + curr[j - 1];
                curr[j] = max(move_i, move_j);
            }
        }
        prev=curr;
    }
    return prev[m];
}


int main(){
    string s1 = "aaca";

    // Taulation
    cout<<longestPalindromeSubseq1(s1)<<endl;

    // Space optimmization
    // cout<<longestPalindromeSubseq2(s1)<<endl;

}