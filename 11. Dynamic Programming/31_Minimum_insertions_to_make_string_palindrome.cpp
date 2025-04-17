#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Q. Minimum insertions to make string palindrome

Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

----------------------Intuition:
n - longest palindromic subsequesnce
s1 = "" , s2 = reverse(s1)



We need to find the minimum insertions required to make a string palindrome. Let us keep the “minimum” criteria aside and think, how can we make any given string palindrome by inserting characters?

The easiest way is to add the reverse of the string at the back of the original string as shown below. This will make any string palindrome.

s1 = "abcaa"

palindrome s = s1 + (reverse of s1)
s = abcaaaacba

Here the number of characters inserted will be equal to n (length of the string). This is the maximum number of characters we can insert to make strings palindrome.

The problem states us to find the minimum of insertions. Let us try to figure it out:

To minimize the insertions, we will first try to refrain from adding those characters again which are already making the given string palindrome. For the given example, “aaa”, “aba”,”aca”, any of these are themselves palindromic components of the string. We can take any of them( as all are of equal length) and keep them intact. let say "aaa"

s1="abcaa"

Now, there are two characters(‘b’ and ‘c’) remaining which prevent the string from being a palindrome. We can reverse their order and add them to the string to make the entire string palindrome.

s="abcacba"

In order to minimize the insertions, we need to find the length of the longest palindromic component or in other words, the longest palindromic subsequence.

Minimum Insertion required = n(length of the string) - length of longest palindromic subsequence.

Approach: The algorithm is stated as follows:
    1. We are given a string (say s), store its length as n.
    2. Find the length of the longest palindromic subsequence ( say k)
    3. Return n-k as answer.
*/

// Tabulation--------------------------------------------------
int longestPalindromeSubseq3(string s1) {
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
    return dp[n][m];
}
int minInsertions3(string s1) {
    int n=s1.size();
    return n - longestPalindromeSubseq3(s1);
}



// Space optimization----------------------------------------
int longestPalindromeSubseq4(string s1) {
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
int minInsertions4(string s1) {
    int n=s1.size();
    return n - longestPalindromeSubseq4(s1);
}


int main(){
    string s1 = "mbadm";

    // Taulation
    cout<<minInsertions3(s1)<<endl;

    // Space optimmization
    cout<<minInsertions4(s1)<<endl;
}