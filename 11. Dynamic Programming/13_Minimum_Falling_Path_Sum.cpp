#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Minimum Falling Path Sum

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

[2 1 3]
[6 5 4]
[7 8 9]

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown. 1+5+7=13 and 1+4+8=13

Intuition: variable starting + variable ending
Recursion - upar se nich 
multiple starting point so use a for loop and calculate for each starting point

Tabulation - niche se upar

*/

// Recursion - Time limit exceed ----------------------------------------------------------------
int solve1(int i, int j, int m, int n, vector<vector<int>>& matrix) {
    // Base case 1: If column index is out of bounds, return a large finite value
    if (j < 0 || j >= n) return 1e7;

    // Base case 2: If we reach the last row, return the value at (i, j)
    if (i == m - 1) return matrix[i][j];

    // Compute possible paths for current index down , diagonal_left, diagonal_right
    int down = matrix[i][j] + solve1(i + 1, j, m, n, matrix);
    int diagonal_left = matrix[i][j] + solve1(i + 1, j - 1, m, n, matrix);
    int diagonal_right = matrix[i][j] + solve1(i + 1, j + 1, m, n, matrix);

    // Return the minimum path sum
    return min(down, min(diagonal_left, diagonal_right));
}
int minFallingPathSum1(vector<vector<int>>& matrix) {
    // Time complexity: O(3^m) for every cell we are exploring 3 paths 3*3*3............ exponential in nature
    // Space complexity: O(m) at max we travel to m rows . depth of recursion will m rows 

    int m=matrix.size(); // Number of rows in the matrix
    int n=matrix[0].size(); // Number of cols in the matrix

    // Initialize the minimum path sum to a very large value
    int mini=INT_MAX; 

    // Iterate through each cell in the first row to find the maximum path sum starting from each of them
    for(int j=0;j<n;j++){
        // Calculate the maximum path sum for the last row
        int ans = solve1(0,j, m, n, matrix);
        // Update the minimum path sum if a smaller one is found
        mini = min(mini, ans);
    }
    return mini;
}


// Memoization ---------------------------------------------------------------------------------
int solve2(int i, int j, int m,int n, vector<vector<int>>& matrix, vector<vector<int>>&dp){
   // Base case 1: If column index is out of bounds, return a large finite value
   if (j < 0 || j >= n) return 1e7;

   // Base case 2: If we reach the last row, return the value at (i, j)
   if (i == m - 1) return matrix[i][j];

   if(dp[i][j] != -1) return dp[i][j];

   // Compute possible paths for current index down , diagonal_left, diagonal_right
   int down = matrix[i][j] + solve2(i + 1, j, m, n, matrix, dp);
   int diagonal_left = matrix[i][j] + solve2(i + 1, j - 1, m, n, matrix, dp);
   int diagonal_right = matrix[i][j] + solve2(i + 1, j + 1, m, n, matrix, dp);

   // Return the minimum path sum
   return dp[i][j] = min(down, min(diagonal_left, diagonal_right));
}
int minFallingPathSum2(vector<vector<int>>& matrix) {
    // Time complexity: O(M*N)
    // space complexity: O(M) + O(M*M)

    int m=matrix.size();
    int n=matrix[0].size();

    int mini=INT_MAX;
    vector<vector<int>>dp(m, vector<int>(n,-1)); 
    for(int j=0;j<n;j++){
        int ans = solve2(0,j, m, n, matrix, dp);
        mini = min(mini, ans);
    }
    return mini;
}



// Tabulation ----------------------------------------------------------------------------------
int minFallingPathSum3(vector<vector<int>>& matrix) {
    // Time complexity: O(M*N)
    // space complexity: O(M*N)

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the last row
    for (int j = 0; j < n; j++) {
        dp[m - 1][j] = matrix[m - 1][j];
    }

    // Bottom-up DP calculation
    for (int i = m - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {  // Fixed loop bounds
            
            int up = matrix[i][j] + dp[i + 1][j];

            int diagonal_left = INT_MAX, diagonal_right = INT_MAX;
            if (j - 1 >= 0) {
                diagonal_left = matrix[i][j] + dp[i + 1][j - 1];
            }
            if (j + 1 < n) {  // Fixed bounds check
                diagonal_right = matrix[i][j] + dp[i + 1][j + 1];
            }

            dp[i][j] = min(up, min(diagonal_left, diagonal_right));
        }
    }

    // Find the minimum value in the first row
    int result = INT_MAX;
    for (int j = 0; j < n; j++) {
        result = min(result, dp[0][j]);
    }

    return result;
}


// Space optimization---------------------------------------------------------------------------
int minFallingPathSum4(vector<vector<int>>& matrix) {
    // Time complexity: O(M*N)
    // space complexity: O(N)

    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> prev(n, 0);

    // Initialize the last row
    for (int j = 0; j < n; j++) {
        prev[j] = matrix[m - 1][j];
    }

    // Bottom-up DP calculation
    for (int i = m - 2; i >= 0; i--) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++) {  // Fixed loop bounds
            
            int up = matrix[i][j] + prev[j];

            int diagonal_left = INT_MAX, diagonal_right = INT_MAX;
            if (j - 1 >= 0) {
                diagonal_left = matrix[i][j] + prev[j - 1];
            }
            if (j + 1 < n) {  // Fixed bounds check
                diagonal_right = matrix[i][j] + prev[j + 1];
            }

            curr[j] = min(up, min(diagonal_left, diagonal_right));
        }
        prev=curr;
    }

    // Find the minimum value in the first row
    int result = INT_MAX;
    for (int j = 0; j < n; j++) {
        result = min(result, prev[j]);
    }

    return result;
}


int main(){
    vector<vector<int>>matrix={
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };

    // Recursion - trying all possible path - time limit exceed
    cout<<minFallingPathSum1(matrix)<<endl;

    // Memoization - use dp to reduce repetetive calculation
    cout<<minFallingPathSum2(matrix)<<endl;

    // Tabulation - reduce the extra recursion stack space 
    cout<<minFallingPathSum3(matrix)<<endl;

    // space optimization - best space optimal solution
    cout<<minFallingPathSum4(matrix)<<endl;

}
