#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top. (1 step + 1 step) and (2 steps)

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

int brute_climbStairs(int n) {
    // Time complexity: O(n)
    // space complexiy: O(n)

    // base case
    if(n==1) return 1;

    vector<int> dp(n+1,-1);

    dp[0]=1;

    // only 1 way to reach at 1 i.e (0->1)
    dp[1]=1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    return dp[n];
}

int optimal_climbStairs(int n) {
    // Time complexity: O(n)
    // space complexiy: O(1)

    /* Intuition: If we closely look the relation, dp[i] =  dp[i-1] + dp[i-2] we see that it almost matches the problem “fibonacci numbers”*/

    if(n==1) return 1;

    int prev = 1, curr_i = 1;
    for (int i = 2; i <= n; i++) {
        int temp = curr_i;
        curr_i = prev + curr_i;
        prev = temp;
    }
    return curr_i;
}

int main(){
    int n=5;

    // Tabulation 
    cout<<brute_climbStairs(n)<<endl;

    // space optimized
    cout<<optimal_climbStairs(n)<<endl;
}

