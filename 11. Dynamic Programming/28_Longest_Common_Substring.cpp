#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest common substring

You are given two strings, 'str1' and 'str2'. You have to find the length of the longest common substring.
A substring is a continuous segment of a string. For example, "bcd" is a substring of "abcd", while "acd" or "cda" are not.

Input: ‘str1’ = “abcjklp” , ‘str2’ = “acjkp”.
Output: 3
Explanation:  The longest common substring between ‘str1’ and ‘str2’ is “cjk”, of length 3.


Intuition: 
We can modify the approach we used in the article Longest Common Subsequence, in order to find the longest common substring. The main distinguishing factor between the two is the consecutiveness of the characters.

While finding the longest common subsequence, we were using two pointers (ind1 and ind2) to map the characters of the two strings. We will again have the same set of conditions for finding the longest common substring, with slight modifications to what we do when the condition becomes true.

We will try to form a solution in the bottom-up (tabulation) approach. We will set two nested loops with loop variables i and j.

Thinking in terms of consecutiveness of characters

We have two conditions:
    if(S1[i-1] != S2[j-1]), the characters don’t match, therefore the consecutiveness of characters is broken. So we set the cell value (dp[i][j]) as 0.

    if(S1[i-1] == S2[j-1]), then the characters match and we simply set its value to 1+dp[i-1][j-1]. We have done so because dp[i-1][j-1] gives us the longest common substring till the last cell character (current strings -{matching character}). As the current cell’s character is matching we are adding 1 to the consecutive chain.

Note: dp[n][m] will not give us the answer; rather the maximum value in the entire dp array will give us the length of the longest common substring. This is because there is no restriction that the longest common substring is present at the end of both the strings.


if there is a match (s1[i-1] == s2[j-1]) check diagonally (\) top left diagonal. 
    1. if it is not match then 0  (a!=b)(a!=c)(a!=d)
    2. if it is match then 1 +  check (top left diagonal) dp[i - 1][j - 1]. 
    
E.g. 1
s1 = "abcd", s2 = "abzd"

  a b z d
a 1 0 0 0
b 0 2 0 0
c 0 0 0 0
d 0 0 0 1 

max is 2. ans=2 (ab)

E.g. 2
s1 = "abcd", s2 = "abcd"

  a b c d
a 1 0 0 0
b 0 2 0 0
c 0 0 3 0
d 0 0 0 4 

max is 4. ans=2 (abcd)

for this case we already declare 0 in vector -> vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
So we dont have to write additional base case 

  a b c d
a 1 
b 
c 
d 

Q. if a==a then 1 + what is dp[i-1][j-1]? 
Ans: dp[i-1][j-1] = 0 because we already declare in vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
1-based indexing thats why this is done -> if (s1[i-1] == s2[j-1]) 

*/

// Tabulation------------------------------------------------------------------
int longestCommonSubstring1(string s1, string s2) {
    // Time complexity: O(n*m) 
    // Space complexity: O(n*m)

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    int ans=0;
    int coordinate_x=-1, coordinate_y=-1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > ans){
                    ans = dp[i][j];
                    coordinate_x=i;
                    coordinate_y=j;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    /* 
    Q. Print the longest common substring.
    Intuition: store the coordinate(i,j) of maximum using dp table. 
    To print the string, move to diagonal only coordinate(i,j) ---> (top left corner side) and then reverse the string.    
    */

    int i = coordinate_x;
    int j = coordinate_y;
    string s = "";
    while (i > 0 && j > 0){
        s+=s2[j-1]; 
        i--;
        j--;
    }
    reverse(s.begin(), s.end());
    cout<<"longest common substring is: "<<s<<endl;
    return ans;
}


// Space optimizagtion--------------------------------------------------------
int longestCommonSubstring2(string s1, string s2) {
    // Time complexity: O(n*m) + O(n+m) at worst case
    // Space complexity: O(m)

    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1, 0);

    int ans=0;
    for (int i = 1; i <= n; i++) {
        vector<int>curr(m+1, 0);
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1]) {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
            else {
                curr[j] = 0;
            }
        }
        prev=curr;
    }
    return ans;
}

int main(){
    string s1="aacabdkacaa";
    string s2="aacakdbacaa";

    // Tabulation
    cout<<longestCommonSubstring1(s1,s2)<<endl;

    // Space optimization
    cout<<longestCommonSubstring2(s1,s2)<<endl;
}


