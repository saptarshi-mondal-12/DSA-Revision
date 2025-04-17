#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Intuition: 
We are given two strings, S1, and S2 (suppose of same length n), the simplest approach will be to generate all the subsequences and store them, then manually find out the longest common subsequence.

This naive approach will give us the correct answer but to generate all the subsequences, we will require exponential ( 2n ) time. Therefore we will try some other approaches.

Using Dynamic Programming

We would want to try something that can give us the longest common subsequence on the way of generating all subsequences. To generate all subsequences we will use recursion and in the recursive logic we will figure out a way to solve this problem.

Step 1: Express the problem in terms of indexes.
We are given two strings S1 and S2:

A single variable can’t express both the strings at the same time, so we will use two variables ind1 and ind2. They mean that we are considering string S1 from index 0 ind1 and string S2 from index 0 to S2. So our recursive function will look like this:



Step 2: Explore all possibilities at a given index
Intuition for Recursive Logic
In the function f(ind1,ind2), ind1 and ind2 are representing two characters from strings S1 and S2 respectively.

Now, there can be two possibilities,
    if(S1[ind1] == S2[ind2]) as in the figure below. In this case this common element will represent a unit length common subsequence, so we can say that we have found one character and we can shrink both the strings by 1 to find the longest common subsequence in the remaining pair of strings.

    if(S1[ind1] != S2[ind2]) as in the figure given below. In this case we know that the current characters represented by ind1 and ind 2 will be different. So, we need to compare the ind1 character with shrunk S2 and ind2 with shrunk S1. But how do we make this comparison ?  If we make a single recursive call as we did above to f(ind1-1,ind2-1), we may lose some characters of the subsequence. Therefore we make two recursive calls: one to f(ind1,ind2-1) (shrinking only S1) and one to f(ind1-1,ind2) (shrinking only S2). Then when we return max of both the calls. 
    E.g ec | ce Explore all possibilities.

Sep 3: Return the maximum of the choices
In the first case, we have only one choice but in the second case we have two choices, as we have to return the longest common subsequences, we will return the maximum of both the choices in the second case.

*/


// Recursion-------------------------------------------------------------------
int solve1(int i, int j, string &s1, string &s2) {
    // Base case: If either string is exhausted
    if (i < 0 || j < 0) return 0;

    // If the characters at the current indices match, increment the LCS length
    if (s1[i] == s2[j]) {
        return 1 + solve1(i - 1, j - 1, s1, s2);
    }
    else {
        // If the characters don't match, consider two options: moving either i by -1 or j by -1 to check both possibilities. ec | ce
        int move_i = 0 + solve1(i - 1, j, s1, s2);
        int move_j = 0 + solve1(i, j - 1, s1, s2);
        return max(move_i, move_j);
    }
}
int longestCommonSubsequence1(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    return solve1(n - 1, m - 1, s1, s2);
}




// Memoization----------------------------------------------------------------
int solve2(int i, int j, string &s1, string &s2, vector<vector<int>>&dp) {
    // Base case: If either string is exhausted
    if (i < 0 || j < 0) return 0;

    // If the result for this pair of indices is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current indices match, increment the LCS length
    if (s1[i] == s2[j]) {
        return dp[i][j] = 1 + solve2(i - 1, j - 1, s1, s2, dp);
    } else {
        // If the characters don't match, consider two options: moving either i by -1 or j by -1 to check both possibilities. ec | ce
        int move_i = 0 + solve2(i - 1, j, s1, s2, dp);
        int move_j = 0 + solve2(i, j - 1, s1, s2, dp);
        return dp[i][j] = max(move_i, move_j);
    }
}
int longestCommonSubsequence2(string s1, string s2) {
    // Time complexity: O(n*m) - There are N*M states therefore at max ‘N*M’ new problems will be solved.

    // Space complexity: O(n*m) + O(n*m) -  We are using an auxiliary recursion stack space(O(N+M)) (see the recursive tree, in the worst case, we will go till N+M calls at a time) and a 2D array ( O(N*M)).

    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return solve2(n - 1, m - 1, s1, s2, dp);
}



// Tabulation------------------------------------------------------------------
int longestCommonSubsequence3(string s1, string s2) {
    // Time complexity: O(n*m)
    // Space complexity: O(n*m)

    /*
    To convert the memoization approach to a tabulation one, create a dp array with the same size as done in memoization. 

    Initialization: Shifting of indexes
    In the recursive logic, we set the base case to if(ind1<0 || ind2<0) but we can’t set the dp array’s index to -1. Therefore a hack for this issue is to shift every index by 1 towards the right.

    Recursive code index  = -1, 0, 1, 2, ............n 
    Tabulation code index =  0, 1, 2, 3, ............n+1

    Therefore, now the base case will be if(ind1==0 || ind2==0).

    Similarly, we will implement the recursive code by keeping in mind the shifting of indexes, 
    therefore S1[ind1] will be converted to S1[ind1-1]. Same for others.

    At last we will print dp[N][M] as our answer.*/

    int n = s1.size();
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



// Space optimiztion----------------------------------------------------------
int longestCommonSubsequence4(string s1, string s2) {
    // Time complexity: O(n*m)
    // Space complexity: O(m)

    int n = s1.size();
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
    string s1="abcde";
    string s2="ace";

    // Recursion
    cout<<longestCommonSubsequence1(s1,s2)<<endl;

    // Memoiazation
    cout<<longestCommonSubsequence2(s1,s2)<<endl;

    // Taulation
    cout<<longestCommonSubsequence3(s1,s2)<<endl;

    // Space optimmization
    cout<<longestCommonSubsequence4(s1,s2)<<endl;
}