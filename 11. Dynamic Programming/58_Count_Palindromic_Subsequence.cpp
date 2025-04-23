#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count All Palindromic Subsequence in a given String

Given a string s of length n, the task is to count number of palindromic subsequence (need not necessarily be distinct) present in the string s.

Input: s = “abcd”
Output: 4
Explanation: Palindromic subsequence are : “a” ,”b”, “c” ,”d”

Input: s = “aab”
Output: 4
Explanation: palindromic subsequence are :”a”, “a”, “b”, “aa”

Input: s = “geeksforgeeks”
Output: 81


Intuition: ------------------------------------

Q. Why Subtract?

When s[i] != s[j], we consider:
    count(i + 1, j) — palindromes in the right substring
    count(i, j - 1) — palindromes in the left substring

But there's overlap:
Any palindromic subsequence that lies entirely inside the middle part (s[i+1..j-1]) gets counted twice — once from each side. So, to avoid double-counting, we subtract:

- count(i + 1, j - 1)


Example: s = "abc", i = 0, j = 2 → substring = "abc"

Subproblems:
    count(1, 2) = "bc" → palindromes: "b", "c"
    count(0, 1) = "ab" → palindromes: "a", "b"
    count(1, 1) = "b" → common part → counted twice
    
So we subtract count(1,1) to fix overcounting:

count(0,2) = count(1,2) + count(0,1) - count(1,1)

Why subtract? To remove the duplicate palindromic subsequences that lie in the overlapping subproblem (s[i+1..j-1]). This is a classic principle in dynamic programming called Inclusion-Exclusion.
*/



// Recursion-----------------------------------------------------
bool isPalindrome(string &s) {
    int left = 0, right = s.size() - 1; 
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++; 
        right--;
    }
    return true; 
}
int solve1(string &s, int i, string curr) {
    // Base case: if we've considered all characters in the string
    if (i == s.size()) {
        // Check if the current substring is a palindrome and return 1 if it is, else return 0
        if(isPalindrome(curr) && curr.size()){
            return 1;
        }
        else{
            return 0;
        }
    }

    // Include the current character in the subsequence
    int res1 = solve1(s, i + 1, curr + s[i]);

    // Exclude the current character from the subsequence
    int res2 = solve1(s, i + 1, curr);

    // Return the total count of palindromic subsequences found
    return res1 + res2;
}
int countPalindromicSubsequence1(string s) {
    // Time complexity: Expoential
    return solve1(s, 0, "");
}



// Memoization---------------------------------------------------------------------
int solve2(int i, int j, string s, vector<vector<int>>&dp) {
    // Base case: if the starting index exceeds the ending index
    if (i > j)
        return 0;

    // Base case: if there is only one character, it's a palindrome
    if (i == j)
        return 1;

    // Return the already computed subproblem if it exists
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == s[j]){
        // Count palindromes by including both characters
        // and counting palindromes in the remaining substrings
        dp[i][j] = 1 + solve2(i + 1, j, s, dp) + solve2(i, j - 1, s, dp);
    }
    else{
        // If characters are different, count palindromes by excluding
        // one character from either end and subtracting the overlap
        dp[i][j] = solve2(i + 1, j, s, dp) +
                   solve2(i, j - 1, s, dp) -
                   solve2(i + 1, j - 1, s, dp);
    }
    // Return the computed result for the substring s[i..j]
    return dp[i][j];
}
int countPalindromicSubsequence2(string s) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2) + O(n)

    int n=s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve2(0, n-1, s, dp);
}



// Tabulation----------------------------------------------------------------------
int countPalindromicSubsequence3(string s) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)

    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // Every single character is a palindrome, so initialize diagonal elements
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the table for substrings of length greater than 1
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}



int main(){
    string s="0100110";

    // Recursion
    cout<<countPalindromicSubsequence1(s)<<endl;

    // Memoization
    cout<<countPalindromicSubsequence2(s)<<endl;

    // Tabulation
    cout<<countPalindromicSubsequence3(s)<<endl;
}