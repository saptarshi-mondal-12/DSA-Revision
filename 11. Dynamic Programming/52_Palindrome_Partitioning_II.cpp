#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Palindrome Partitioning II

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Input: s = "a"
Output: 0

Input: s = "ab"
Output: 1

Intution: 
start from front i.e 0. and use simple recursion -> after partitioning can left side is palindrome . if it is 1 + (check for next)
*/

// Recursion -------------------------------------------------------
bool isPalindrome(string temp){
    int i=0;
    int j=temp.size()-1;
    while(i<j){
        if(temp[i]!=temp[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve1(int i, int n, string s){
    // Base case:
    if(i==n) return 0;

    string temp="";
    int mini=INT_MAX;
    for(int j=i;j<n;j++){
        temp+=s[j];
        if(isPalindrome(temp)){
            int cost = 1 + solve1(j+1, n, s);
            mini = min(mini, cost);
        }
    }
    return mini;
}
int minCut1(string s) {
    // Time complexity: Exponential
    // Space complexity: O(N)

    int n=s.size();

    /* Q. Why -1?
    Ans: eg. ABC, it do partition like A|BC, A|B|C| , after c partition is invalid so to avoid extra partition we do -1.
    */
    return solve1(0, n, s) - 1;
}


// Memoization---------------------------------------------------------
int solve2(int i, int n, string s, vector<int>&dp){
    // Base case:
    if(i==n) return 0;

    if(dp[i] != -1) return dp[i];

    string temp="";
    int mini=INT_MAX;
    for(int j=i;j<n;j++){
        temp+=s[j];
        if(isPalindrome(temp)){
            int cost = 1 + solve2(j+1, n, s, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i]=mini;
}
int minCut2(string s) {
    // Time complexity: O(N*N)
    // Space complexity: O(N) + O(N)

    int n=s.size();
    vector<int>dp(n, -1);
    return solve2(0, n, s, dp) - 1;
}



// Tabulation----------------------------------------------------------
int minCut3(string s) {
    // Time complexity: O(N*N)
    // Space complexity: O(N)

    int n=s.size();
    vector<int>dp(n+1, 0);

    for(int i=n-1;i>=0;i--){
        string temp="";
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost = 1 + dp[j+1];
                mini = min(mini, cost);
            }
        }
        dp[i]=mini;
    }

    return dp[0]-1;
}

int main(){
    string s = "aabbaacde";

    // Recursion
    cout<<minCut1(s)<<endl;

    // Memoization
    cout<<minCut2(s)<<endl;

    // Tabulation
    cout<<minCut3(s)<<endl;
}