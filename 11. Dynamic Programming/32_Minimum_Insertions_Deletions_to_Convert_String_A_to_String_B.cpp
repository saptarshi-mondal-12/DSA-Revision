#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Minimum Number of Deletions and Insertions / Leetcode 583

You are given 2 non-empty strings 's1' and 's2' consisting of lowercase English alphabets only.
In one operation you can do either of the following on 's1':
    (1) Remove a character from any position in 's1'.
    (2) Add a character to any position in 's1'.

Find the minimum number of operations required to convert string 's1' into 's2'.

Input: 's1' = "abcd", 's2' = "anc"
Output: 3
Explanation:
Here, 's1' = "abcd", 's2' = "anc".
In one operation remove 's1[3]', after this operation 's1' becomes "abc".    
In the second operation remove 's1[1]', after this operation 's1' becomes "ac".
In the third operation add 'n' in 's1[1]', after this operation 's1' becomes "anc".

Hence, the minimum operations required will be 3. It can be shown that there's no way to convert s1 into s2 in less than 3 moves.





----------Intuition: Using LCS

We need to find the minimum operations required to convert string str1 to str2. Let us keep the “minimum” criteria aside and think, what maximum operations will be required for this conversion?

The easiest way is to remove all the characters of str1 and then insert all the characters of str2. In this way, we will convert str1 to str2 with ‘n+m’ operations. (Here n and m are the length of strings str1 and str2 respectively). 

The problem states us to find the minimum of insertions. Let us try to figure it out:

To minimize the operations, we will first try to refrain from deleting those characters which are already present in str2. More extensively, we refrain from deleting those characters which are common and come in the same order. To minimize the operations, we would like to keep the maximum common characters coming in the same order intact. These maximum characters are the characters of the longest common subsequence. 
We will first keep the longest common subsequence of the str1 and str2 intact in str1 and delete all other characters from str1

In order to minimize the operations, we need to find the length of the longest common subsequence.

-----------Minimum Operations required = (n + m) - 2*(LCS)

Here n and m are the length of str1 and str2 respectively 


Q. What can i not touch?
If i touch the minimum items then operation will be automatically minimum.
find length of longest common subsequence that need to untouch

n=4, s1="abcd"
m=3, s2="anc"
common="ac", ac is the longest common portion. If i keek this entact there it minimum operations will be 
n+m - 2*length_of(Longest_Common)
(4+3) - 2*(2)
7 - 4 = 3 
ans = 3 (2 deletion and 1 indertion which is correct )

Q. why this 2 in 2*length_of(Longest_Common)?
Ans: because "ac" present in both s1 & s2 which is longest common subsequence.

*/

// Tabulation=-----------------------------------------------------------
int longestCommonSubsequence3(string s1, string s2) {
    // Time complexity: O(n*m)
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
    return dp[n][m];
}
int canYouMake3(string &s1, string &s2){
    int n=s1.size();
    int m=s2.size();
    return (n+m) - 2*(longestCommonSubsequence3(s1,s2));
}



// Space optimization-----------------------------------------------------
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
int canYouMake4(string &s1, string &s2){
    int n=s1.size();
    int m=s2.size();
    return (n+m) - 2*(longestCommonSubsequence4(s1,s2));
}




int main(){
    string s1="abcd";
    string s2="anc";

    // Taulation
    cout<<canYouMake3(s1,s2)<<endl;

    // Space optimmization
    cout<<canYouMake4(s1,s2)<<endl;
}