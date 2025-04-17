#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

https://takeuforward.org/data-structure/wildcard-matching-dp-34/
*/


// Recursion -----------------------------------------------------------------------------------
bool solve1(int i, int j, string &pattern, string &text){
    // Base case 1: if both string is exhausted means pattern="" and text="", return true
    if(i<0 && j<0) return true;

    // Base case 2: if string 1 (pattern) is exhauted and string 2 (text) has left some portion
    if(i<0 && j>=0) return false;

    // Base case 3: if string 2 (text) is exhausted and strign 1 (pattern) has left some portion then check if string if string 1 (pattern) contain only * (because string 2 i.e text is empty and if string 1 pattern has only * then we can match with nothing, (including the empty sequence).
    if(i>=0 && j<0){
        // check if a substring of S1 contains only '*'
        for(int t=0;t<=i;t++){
            if(pattern[t]!='*'){
                return false;
            }
        }
        return true;
    }

    // If the characters at the current positions match or S1 has a '?'
    if(pattern[i] == text[j] || pattern[i] == '?'){
        return solve1(i-1, j-1, pattern, text);
    }
    else{
        // Two options: either '*' represents an empty string or it matches a character in S2
        if(pattern[i] == '*'){
            return solve1(i-1, j, pattern, text) || solve1(i, j-1, pattern, text );
        }else{
            return false;
        }
    }
}
bool isMatch1(string pattern, string text) {
    // Time complexity: exponential
    // Space complexity: O(N+M)

    int n=pattern.size();
    int m=text.size();

    return solve1(n-1, m-1, pattern, text);
}



// Memoization-----------------------------------------------------------------------
bool solve2(int i, int j, string &pattern, string &text, vector<vector<int>>&dp){
    // Base case 1: if both string is exhausted means pattern="" and text="", return true
    if(i<0 && j<0) return true;

    // Base case 2: if string 1 (pattern) is exhauted and string 2 (text) has left some portion
    if(i<0 && j>=0) return false;

    // Base case 3: 
    if(i>=0 && j<0){
        // check if a substring of S1 contains only '*'
        for(int t=0;t<=i;t++){
            if(pattern[t]!='*'){
                return false;
            }
        }
        return true;
    }

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    if(pattern[i] == text[j] || pattern[i] == '?'){
        return dp[i][j] = solve2(i-1, j-1, pattern, text, dp);
    }
    else{
        if(pattern[i] == '*'){
            return dp[i][j] = solve2(i-1, j, pattern, text, dp) || solve2(i, j-1, pattern, text, dp);
        }else{
            return false;
        }
    }
}
bool isMatch2(string pattern, string text) {
    // Time complexity: O(N*M)
    // Space complexity: O(N*M) + O(N+M)

    int n=pattern.size();
    int m=text.size();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return solve2(n-1, m-1, pattern, text, dp);

}



// Tabulation-------------------------------------------------------------------
bool isMatch3(string pattern, string text) {
    // Time complexity: O(N*M)
    // Space complexity: O(N*M)

    int n=pattern.size();
    int m=text.size();
    vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));

    // Base case 1
    dp[0][0] = true;

    // Base case 2
    for(int j=1;j<=m;j++){
        dp[0][j] = false;
    }

    // Base case 3: dp[i][0] = true if pattern[0..i-1] are all '*'
    for (int i = 1; i <= n; i++) {
        bool allStars = true;
        for (int t = 1; t <= i; t++) {
            if (pattern[t - 1] != '*') {
                allStars = false;
                break;
            }
        }
        dp[i][0] = allStars;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                if(pattern[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[n][m];
}



// Space optimization------------------------------------------------------------------------------------------------------------
bool isMatch4(string pattern, string text) {
    // Time complexity: O(N*M)
    // Space complexity: O(M)

    int n=pattern.size();
    int m=text.size();
    vector<bool>prev(m+1, false);

    // Base case 1
    prev[0] = true;


    for(int i=1;i<=n;i++){
        vector<bool>curr(m+1, false);

        // Base case 3: dp[i][0] = true if pattern[0..i-1] are all '*'
        bool allStars =true;
        for (int t = 1; t <= i; t++) {
            if (pattern[t - 1] != '*') {
                allStars = false;
                break;
            }
        }
        curr[0] = allStars;

        for(int j=1;j<=m;j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                curr[j] = prev[j-1];
            }
            else{
                if(pattern[i-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }else{
                    curr[j] = false;
                }
            }
        }
        prev=curr;
    }
    return prev[m];
}



int main(){
    string pattern="";
    string text="";

    // Recursion
    cout<<isMatch1(pattern, text)<<endl;

    // Memoization
    cout<<isMatch2(pattern, text)<<endl;

    // Tabulation
    cout<<isMatch3(pattern, text)<<endl;

    // Space optimization
    cout<<isMatch4(pattern, text)<<endl;
}