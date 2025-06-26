#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Print Longest Common Subsequence 

The dp[n][m] gives us the length of the longest common subsequence.

We will use the dp array from tabulation to form the LCS string. 
For that, we need to think, about how did the dp array was originally filled. The tabulation approach used 1-based indexing. We also write the characters corresponding to the indexes of the dp array:

Now, let us see what were the conditions that we used while forming the dp array:
    if(S1[i-1] == S2[j-1]), then return 1 + dp[i-1][j-1]
    if(S1[i-1] != S2[j-1]) , then return 0 + max(dp[i-1][j],dp[i][j-1])

These two conditions along with the dp array give us all the required information required to print the LCS string.

Approach:
The algorithm approach is stated below:

1. We will fill the string str from the last by maintaining a pointer. 

2. We will start from the right-most cell of the dp array, initially i=n and j=m.

3. At every cell, we will check if S1[i-1] == S2[j-1], if it is then it means this character is a part of the longest common substring. So we will push it to the str (at last). Then we will move to the diagonally top-left(↖)  cell by assigning i to i-1 and j to j-1.

4. Else, this character is not a part of the longest common subsequence. It means that originally this cell got its value from its left cell (←) or from its top cell (↑). Whichever cell’s value will be more of the two, we will move to that cell.

5. We will continue till i>0 and j>0, failing it we will break from the loop.

6. At last we will get our lcs string in “str”.

NOTE: DP table fillup -> max(dp[i-1][j], dp[i][j-1]);







*/

// Tabulation------------------------------------------------------------------
string longestCommonSubsequence3(string s1, string s2) {
    // Time complexity: O(n*m) + O(n+m) at worst case
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

    // Print the dp array 
    //     b d g e k
    //   0 0 0 0 0 0 
    // a 0 0 0 0 0 0 
    // b 0 1 1 1 1 1 
    // c 0 1 1 1 1 1 
    // d 0 1 2 2 2 2 
    // e 0 1 2 2 3 3 

    /* ans is stored over dp[5][5] = 3

    dp[5][5]
       |  |
       v   -------> bdgek
       abcde

    dp[4][2]
       |  |
       v   -------> bd   ===> 2  (bd and bd of length 2) length of lcs till here is 2
       abcd

    In tabulation we wrote 2 condition : 

            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                int move_i = 0 + dp[i - 1][j];
                int move_j = 0 + dp[i][j - 1];
                dp[i][j] = max(move_i, move_j);
            }
    
    So if (s1[i-1] == s2[j-1]) we do 1 + diagonal ==> 1 + dp[i - 1][j - 1];
    and if not equal we take max of these :
            int move_i = 0 + dp[i - 1][j];
            int move_j = 0 + dp[i][j - 1];
            dp[i][j] = max(move_i, move_j);
    
    Similarly, we do backtrack 
    starting from d[n][m] and:  
                            if equal we add char to our answer and move diagonal
                            and if not equal then whichever is max we move that side (either dp[i - 1][j] or dp[i][j - 1]).
    
    START DP[5][5]

        "e" != "k"

        we move to col-1 i.e move_j because move_j is greater than move_i (3>2)

        now dp[5][4]

        "e" == "e"  ==> add to our answer 
        moveing diagonal dp[i-1][j-1]

        now dp[4][3] 
        so on

    */

    
    cout<<"Length of Longest common subsequence = "<<dp[n][m]<<endl;

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
    return ans;
}

int main(){
    string s1="abcde";
    string s2="bdgek";

    // Tabulation
    cout<<longestCommonSubsequence3(s1,s2)<<endl;
}