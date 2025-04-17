#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/* Q. Count Distinct Subsequences

Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.


Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
---- --
rabbbit
-- ----
rabbbit
--- ---

Input: s = "babgbag", t = "bag"
Output: 5



--------Intuition: 

Link -> https://takeuforward.org/data-structure/distinct-subsequences-dp-32/

s="babgbag" , t="bag"

i=6, j= 2
if (s[i] == t[j]) the 2 possibilities

    1. take - (i-1, j-1) and move both pointer
    s="babgbag" , t="bag"
             ^         ^
             |         |


    2. (i-1 , j) -> i=5, j=2
    In future we might get another occurrence of t[j] i.e char "g" in string s that's why we move only i and j remain at same position

    s="babgbag" , t="bag"
            ^          ^
            |          |
else
    if not match move i only



Base Cases:
We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1.

    1. if j<0, it means we have matched all characters of S2 with characters of S1, so we return 1.
    
    2. if i<0, it means we have checked all characters of S1 but we are not able to match all characters of S2, therefore we return 0.
*/



// Recursion --------------------------------------------------------------------------
int solve1(int i, int j, string &s, string &t){
    // base case 1: suppose i=2, j=-1 -> (2, -1) means we have matched all characters of S2 with characters of S1, so we return 1.
    if (j < 0){
        return 1;
    }

    // base case 2: if i<0, it means we have checked all characters of S1 but we are not able to match all characters of S2, therefore we return 0.
    if (i < 0){
        return 0;
    }

    int count = 0;

    // If the characters match, consider two options
    if (s[i] == t[j]){
        // 1. either take the character and move both pointer i.e (i-1, j-1)
        int take = solve1(i - 1, j - 1, s, t);

        // 2. or leave the character in s i.e (i-1, j);
        int notTake = solve1(i - 1, j, s, t);
        count = (notTake + take) % mod;
    }
    else{
        // If characters don't match, just leave the character in s and continue matching t
        count = solve1(i - 1, j, s, t);
    }

    return count;
}
int distinctSubsequences1(string &s, string &t){
    // Time complexity: (2^n) * (2^m) Exponential in nature, there can be a lot of comparisions. 2^n of string s and 2^m for string t.
    // space complexity: O(N+M)

    int n = s.size();
    int m = t.size();
    return solve1(n - 1, m - 1, s, t);
}



// Memoization -----------------------------------------------------------------------
int solve2(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    // base case 1:
    if (j < 0){
        return 1;
    }

    // base case 2:
    if (i < 0){
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1) return dp[i][j];

    int count = 0;

    if (s[i] == t[j]){
        int take = solve2(i - 1, j - 1, s, t, dp);
        int notTake = solve2(i - 1, j, s, t, dp);
        count = (notTake + take) % mod;
    }
    else{
        count = solve2(i - 1, j, s, t, dp);
    }
    dp[i][j] = count;
    return count;
}
int distinctSubsequences2(string &s, string &t){
    // Time complexity: O(N*M)
    // space complexity: O(N*M) + O(N+M) recursion stack space 

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve2(n - 1, m - 1, s, t, dp);
}



// Tabulation ------------------------------------------------------------------------------
int distinctSubsequences3(string &s, string &t){
    // Time complexity: O(N*M)
    // space complexity: O(N*M)

    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int mod = 1e9 + 7;

    // Base case 1: if j==0 then return 1
    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    // Bzse case 2: 
    for (int j = 1; j <= m; j++){
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++){
            if (s[i - 1] == t[j - 1]){
                int take = dp[i - 1][j - 1];
                int notTake = dp[i - 1][j];
                dp[i][j] = (notTake + take) % mod;
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}



// Space optimization------------------------------------------------------------------------
int distinctSubsequences4(string &s, string &t){
    // Time complexity: O(N*M)
    // space complexity: O(M)

    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0);
    int mod = 1e9 + 7;

    prev[0] = 1;

    for (int i = 1; i <= n; i++){
        vector<int> curr(m + 1, 0);
        curr[0] = 1; 
        // Q. Why curr[0] = 1 because if string t i.e j is exhausted (j==0), it should be 1 that's why we pre initialize 
        for (int j = 1; j <= m; j++){
            if (s[i - 1] == t[j - 1]){
                int take = prev[j - 1];
                int notTake = prev[j];
                curr[j] = (notTake + take) % mod; 
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[m];
}




int main()
{
    string s1 = "rabbbit";
    string s2 = "rabbit";

    // Recursion
    cout << distinctSubsequences1(s1, s2) << endl;

    // Memoization
    cout << distinctSubsequences2(s1, s2) << endl;

    // Tabulation
    cout << distinctSubsequences3(s1, s2) << endl;

    // Space optimization
    cout << distinctSubsequences4(s1, s2) << endl;
}