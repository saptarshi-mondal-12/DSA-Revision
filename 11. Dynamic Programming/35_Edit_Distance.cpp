#include<iostream>
using namespace std;
#include<bits/stdc++.h>


/* Q. Edit Distance 

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
1. Insert a character
2. Delete a character
3. Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


--------Intuition: 

For every index of string S1, we have three options to match that index with string S2, i.e replace the character, remove the character or insert some character at that index. Therefore, we can think in terms of string matching path as we have done already in previous questions.
As there is no uniformity in data, there is no other way to find out than to try out all possible ways. To do so we will need to use recursion.

Steps to form the recursive solution: 

We will first form the recursive solution by the three points mentioned in the Dynamic Programming Introduction. 

Step 1: Express the problem in terms of indexes.
We are given two strings. We can represent them with the help of two indexes i and j. Initially, i=n-1 and j=m-1, where n and m are lengths of strings S1 and S2. Initially, we will call f(n-1,m-1), which means the minimum number of operations required to convert string S1[0…n-1] to string S2[0…m-1].

We can generalize this as follows:
f(i,j) = Minimum no of operations required to convert string s1[0..i] to s2[0..j] using three given operation.

Step 2: Try out all possible choices at a given index.
Now, i and j represent two characters from strings S1 and S2 respectively. There are only two options that make sense: either the characters represented by i and j match or they don’t.

(i) When the characters match
    if(S1[i]==S2[j])
If this is true, now as the characters at i and j match, we would not want to do any operations to make them match, so we will just decrement both i and j by 1 and recursively find the answer for the remaining string portion. We return 0+f(i-1,j-1).

(ii) When the characters don’t match
    if(S1[i] != S2[j]) is true, then we have to do any of three operations to match the characters. We have three options, we will analyze each of them one by one.

    Case 1: Inserting a character return 1+f(i-1,j) // Insertion of character.
    Case 2: Deleting a character return 1+f(i,j-1) // Deletion of character.
    Case 3: Replacing a character return 1+f(i-1,j-1) // Replacement of character.

Step 3: Return the minimum of all choices.
As we have to return the minimum number of operations, we will return the minimum of all operations.

Base Cases:
    We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1., i,e we exhaust either S1 or S2 respectively.

*/

// Recursion------------------------------------------------------------------------
int solve1(int i, int j, string &s1, string &s2){
    // Base case 1: if string s1 is exhausted i.e i < 0
    // means total (j+1) character is need to be inserted in s1 
    if(i<0){
        return j+1;
    }

    // Base case 2: if string s2 is exhausted i.e j < 0 
    // means total (i+1) character is need to be deleted from string s1
    if(j<0){
        return i+1;
    }

    // Exploring all possibilities 
    if(s1[i] == s2[j]){
        return 0 + solve1(i-1, j-1, s1, s2);

    }else{
        // 1. replace
        int replace = solve1(i-1, j-1, s1, s2);
        // 2. delete
        int del = solve1(i-1, j, s1, s2);
        // 3. insert
        int insert = solve1(i, j-1, s1, s2);

        return 1 + min(insert, min(del, replace));
    }

}
int minDistance1(string s1, string s2) {
    // Time complexity: (3^n) * (3^m)
    // Space complexity: O(N+M)

    int n=s1.size();
    int m=s2.size();

    return solve1(n-1, m-1, s1, s2);
}



// Memoization-----------------------------------------------------------------------
int solve2(int i, int j, string &s1, string &s2, vector<vector<int>>dp){
    // Base case 1: if string s1 is exhausted i.e i < 0
    if(i<0){
        return j+1;
    }

    // Base case 2: if string s2 is exhausted i.e j < 0
    if(j<0){
        return i+1;
    }

    if(dp[i][j] != -1) return dp[i][j];

    // Exploring all possibilities 
    if(s1[i] == s2[j]){
        return dp[i][j] = solve2(i-1, j-1, s1, s2, dp);

    }else{
        // replace
        int replace = solve2(i-1, j-1, s1, s2, dp);
        // delete
        int del = solve2(i-1, j, s1, s2, dp);
        // insert
        int insert = solve2(i, j-1, s1, s2, dp);

        return dp[i][j] =  1 + min(insert, min(del, replace));
    }

}
int minDistance2(string s1, string s2) {
    // Time complexity: O(N*M)
    // Space complexity: O(N*M) + O(N+M)

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>>dp(n, vector<int>(m, -1));

    return solve2(n-1, m-1, s1, s2, dp);
}



// Tabulation----------------------------------------------------------------------
int minDistance3(string s1, string s2) {
    // Time complexity: O(N*M)
    // Space complexity: O(N*M)

    int n=s1.size();
    int m=s2.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    // Base case 1:
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    // Base case 2:
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                int replace = dp[i-1][j-1];
                // 2. Delete the character at S1[i-1]
                int del = dp[i-1][j];
                // 3. Insert the character at S2[j-1] into S1
                int insert = dp[i][j-1];
                
                dp[i][j] = 1 + min(replace, min(insert, del));
            }
        }
    }

    // The value at dp[n][m] contains the edit distance
    return dp[n][m];
}




// Space Optimization--------------------------------------------------------------
int minDistance4(string s1, string s2) {
    // Time complexity: O(N*M)
    // Space complexity: O(M)

    int n=s1.size();
    int m=s2.size();

    vector<int>prev(m+1, 0);

    // Base case 2:
    for(int j=0;j<=m;j++){
        prev[j] = j;
    }

    for (int i = 1; i <= n; i++) {
        vector<int>curr(m+1, 0);
        // Base case 1:
        curr[0] = i;
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If the characters match, no additional cost
                curr[j] = prev[j - 1];
            } else {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                int replace = prev[j-1];
                // 2. Delete the character at S1[i-1]
                int del = prev[j];
                // 3. Insert the character at S2[j-1] into S1
                int insert = curr[j-1];
                
                curr[j] = 1 + min(replace, min(insert, del));
            }
        }
        prev = curr;
    }

    // The value at dp[n][m] contains the edit distance
    return prev[m];
}




int main(){
    string s1="horse";
    string s2="ros";

    // Recursion
    cout<<minDistance1(s1,s2)<<endl;

    // Memoization
    cout<<minDistance2(s1,s2)<<endl;

    // Tabulation
    cout<<minDistance3(s1,s2)<<endl;

    // Space optimization
    cout<<minDistance4(s1,s2)<<endl;


}