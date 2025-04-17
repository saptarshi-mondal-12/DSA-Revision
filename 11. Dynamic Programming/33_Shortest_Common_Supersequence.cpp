#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Shortest common SuperSequence 

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

We need to return the length of the longest common subsequence and the string as well.




------------------Intuition: 
Same LCS code with modification in printing answer


if match then 1 + previous diaginal i.e dp[i-1][j-1]
    dp[i][j] = 1 + dp[i - 1][j - 1];

if not match take max(up, left) i.e max(dp[i-1][j] , dp[i][j-1])
    int move_i = 0 + dp[i - 1][j];
    int move_j = 0 + dp[i][j - 1];
    dp[i][j] = max(move_i, move_j);


DRAW DP TABLE 
        
        j=0 1 2 3 4 5
            g r o o t
        ---------------
    i=0 | 0 0 0 0 0 0
    b 1 | 0 0 0 0 0 0
    r 2 | 0 0 1 1 1 1
    u 3 | 0 0 1 1 1 1
    t 4 | 0 0 1 1 1 2
    e 5 | 0 0 1 1 1 2 


If we keep the “shortest” criteria aside, what can be a way to generate a supersequence given two strings. One easy way is to concat the given strings (write one after the other), this will always give us a supersequence for any pair of given strings.
s1="brute", s2="groot"
ans = "brutegroot" length is 11

This can be said as the worst case with time complexity of O(n+m), where n and are the lengths of strings S1 and S2 respectively.

Q. How can we improve from this naive approach?

If we think a little, there are some common characters that we can avoid writing for both the strings separately. These common characters can’t be all the common characters. They are the characters that are common and come in the same order. In other words, they are the characters of the longest common subsequence. 

In an optimum solution, the characters of the longest common subsequence are written only once and other characters are placed around them. For every character that belongs to the longest common subsequence, the non-lcs characters coming before them in the strings S1 and S2 are placed before the lcs-character in the answer string.

Q. Length of Shortest Common Supersequence?
From the explanation above, we can see that characters of lcs need to be covered only once. Therefore, the length of the shortest Common supersequence = n + m -k, where (n and m are lengths of S1 and S2, and k is the length of the lcs string).

---------[ Length of Shortest Common Supersequence = (n+m) - lcs(s1,s2) ]---------


Now, instead of the length, we are interested in finding the shortest supersequence string itself. 
Approach: 

We will start from the right-most cell of the dp array, initially i=n and j=m

To form the string, we will work in a reverse manner.
    if(S1[i-1] == S2[j-1]), this means the character is an lcs character and needs to be included only once from both the strings, so we add it to the ans string and reduce both i and j by 1. We reduce them simultaneously to make sure the character is counted only once.

    if(S1[i-1] != S2[j-1]), this means that the character is a non-lcs character and then we move the pointer to the top cell or left cell depending on which is greater. This way non-lcs characters will be included separately in the right order.

Algorithm steps :
    1. We start from cell dp[n][m]. Initially i=n and j=m.
    
    2. At every cell, we will check if S1[i-1] == S2[j-1], if it is then it means this character is a part of the longest common subsequence. So we will push it to the ans string str. Then we will move to the diagonally top-left(↖)  cell by assigning i to i-1 and j to j-1.
    
    3. Else, this character is not a part of the longest common subsequence so we include it in ans string. Originally this cell got its value from its left cell (←) or from its top cell (↑). Whichever cell’s value will be more of the two, we will move to that cell.
    
    4. We will continue till i>0 and j>0, failing it we will break from the loop.
    
    5. After breaking, either i>0 or j>0 (only one condition will fail to break from the while loop), if(i>0) we push all the characters from S1 to ans string, else if(j>0), we push all the remaining characters from S2.

    6.At last, we reverse the ‘ans’ string and we get our answer.
*/

// Tabulation------------------------------------------------------------------
string longestCommonSubsequence3(string s1, string s2) {
    // Time complexity: O(n*m) + O(n+m)
    // Space complexity: O(n*m)


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


    // Generating string using DP table
    int length = dp[n][m];
    string ans="";

    int i=n;
    int j=m;

    // i-> represent index of string s1 (1-based indexing)
    // j-> represent index of string s2 (1-based indexing)

    while(i>0 && j>0){
        // if both are equal we need to add only one char to our answer
        if(s1[i-1] == s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }
        // if up is maximum means row is reduce i.e i, Then add s1[i-1] char to our answer. 
        else if(dp[i-1][j] > dp[i][j-1]){
            ans+=s1[i-1];
            i--;
        }
        // if left is maximum means column is reduce i.e j, Then add s2[j-1] char to our answer. 
        else{
            ans+=s2[j-1];
            j--;
        }
    }

    // NOTE : Either i is exhausted or j is exhausted. So whichever is not not exhausted add remaining char to answer. 

    // if i is not exhausted add char to our answer
    while(i>0){
        ans+=s1[i-1];
        i--;
    }

    // if j is not exhausted add char to our answer
    while(j>0){
        ans+=s2[j-1];
        j--;
    }

    // Reverse the answer because we mov the dp table from bottom to top which give our answer in reverse patteren so reverse it. 
    reverse(ans.begin(), ans.end());

    return ans;
}
string shortestCommonSupersequence(string s1, string s2) {
    string ans = longestCommonSubsequence3(s1, s2); 
    cout<<ans.size()<<endl;
    return ans; 
}




int main(){
    string s1="brute";
    string s2="groot";

    // Tabulation
    cout<<shortestCommonSupersequence(s1,s2)<<endl;
}