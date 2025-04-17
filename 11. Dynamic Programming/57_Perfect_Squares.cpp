#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/


// Recursion--------------------------------------------------------
int solve1(int n){
    // Base case
    if (n == 0) return 0;

    int minCount = INT_MAX;

    // Try every perfect square less than or equal to n
    for (int i = 1; i * i <= n; i++) {
        int square = i * i;
        int count = 1 + solve1(n - square);
        minCount = min(minCount, count);
    }
    return minCount;
}
int numSquares1(int n) {
    return solve1(n);
}


// Memoization------------------------------------------------------
int solve2(int n, vector<int>&dp){
    // Base case
    if (n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int minCount = INT_MAX;

    // Try every perfect square less than or equal to n
    for (int i = 1; i * i <= n; i++) {
        int square = i * i;
        int count = 1 + solve2(n - square, dp);
        minCount = min(minCount, count);
    }
    return dp[n] = minCount;
}
int numSquares2(int n) {
    vector<int>dp(n+1,-1);
    return solve2(n, dp);
}


// Tabulation-------------------------------------------------------
int numSquares3(int n) {
    vector<int>dp(n+1,0);
    for(int i=1;i<=n;i++){
        int minCount = INT_MAX;
        // Try every perfect square less than or equal to n
        for (int j = 1; j * j <= i; j++) {
            int square = j * j;
            int count = 1 + dp[i - square];
            minCount = min(minCount, count);
        }
        dp[i] = minCount;
    }
    return dp[n]; 
}

int main(){
    int n=12;

    // Recursion
    cout<<numSquares1(n)<<endl;

    // Memoization
    cout<<numSquares2(n)<<endl;

    // Tabulation
    cout<<numSquares3(n)<<endl;

}