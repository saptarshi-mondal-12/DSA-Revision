#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Minimum Cost to Cut a Stick

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:
Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
Return the minimum total cost of the cuts.

Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

Intuition: 
https://takeuforward.org/data-structure/minimum-cost-to-cut-the-stick-dp-50/
*/

// Recursion ---------------------------------------------------------------
int solve1(int i, int j, vector<int>cuts){
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    int mini = INT_MAX;

    // I can do any one as 1st cut so -> run a for loop from 1 to j and find minimum cost
    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind' and solve for left sub problem & right sub problem because i did a partition on index ind.
        int ans = cuts[j + 1] - cuts[i - 1] + solve1(i, ind - 1, cuts) + solve1(ind + 1, j, cuts);
        mini = min(mini, ans);
    }
    return mini;
}
int minCost1(int n, vector<int>cuts) {
    // Time complexity: Exponential
    // space complexity: O(N)

    int c = cuts.size();

    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Call the recursive function to find the minimum cost.
    return solve1(1, c, cuts);
        
}


// Memoization-------------------------------------------------------------
int solve2(int i, int j, vector<int>cuts,  vector<vector<int>>&dp){
    // Base case: If i is greater than j, there are no cuts to consider.
    if (i > j) {
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        // Calculate the cost for making a cut at position 'ind'
        int ans = cuts[j + 1] - cuts[i - 1] + solve2(i, ind - 1, cuts, dp) + solve2(ind + 1, j, cuts, dp);
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}
int minCost2(int n, vector<int>cuts) {
    // Time complexity: O(N*N*N)
    // space complexity: O(N*N) + O(N)

    int c = cuts.size();

    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values.
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    // Call the recursive function to find the minimum cost.
    return solve2(1, c, cuts, dp);  
}


// Tabulation--------------------------------------------------------------
int minCost3(int n, vector<int>cuts){
    // Time complexity: O(N*N*N)
    // space complexity: O(N*N)

    // NOTE: n : length of stcick, c=length of cut array

    int c = cuts.size();

    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    // Create a DP table to store calculated values. c+2 because i is starting from c, for that +1 & another +1 because we do ind+1 -> dp[ind + 1][j] that's why c+2 
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = 1; j <= c; j++) {
            if (i > j) continue;

            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++) {
                // Calculate the cost for making a cut at position 'ind'.
                int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}


int main(){
    int n=7;
    vector<int>cuts={1,3,4,5};

    // Recursion
    cout<<minCost1(n, cuts)<<endl;

    // Memoization
    cout<<minCost2(n, cuts)<<endl;

    // Tabulation
    cout<<minCost3(n, cuts)<<endl;
}