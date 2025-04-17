#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Intuition: This question is a slight modification of the question discussed in Grid Unique Path 2 . In the previous problem, there were obstacles whereas this problem has cost associated with a cell and we need to return the minimum cost path.

Greedy Solution doesn’t work here reason try with your example in pen paper

Step 1: Express the problem in terms of indexes.
We are given two variables N and M, representing the dimensions of the matrix. 
We can define the function with two parameters i and j, where i and j represent the row and column of the matrix.
We will be doing a top-down recursion, i.e we will move from the cell[M-1][N-1] and try to find our way to the cell[0][0]. Therefore at every index, we will try to move up and towards the left.

Base Case:
There will be three base cases:
    1. When i=0 and j=0, that is we have reached the destination so we can add to path the current cell value, hence we return mat[0][0].

    2. When i<0 or j<0, it means that we have crossed the boundary of the matrix and we don’t want to find a path from here, so we return a very large number( say, 1e9) so that this path is rejected by the calling function.


Step 2: Try out all possible choices at a given index.
As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←). To go upwards, we will reduce i by 1, and move towards left we will reduce j by 1.
Now when we get our answer for the recursive call (f(i-1,j) or f(i,j-1)), we need to also add the current cell value to it as we have to include it too for the current path sum.

Step 3:  Take the minimum of all choices
As we have to find the minimum path sum of all the possible unique paths, we will return the minimum of the choices(up and left) 

*/

// Recursion----------------------------------------------------------------------
int solve1(int i, int j, vector<vector<int>>& grid){
    // Base case 1: if we reach our destination i.e (0,0) return grid[0][0]
    if (i==0 && j==0){
        return grid[0][0];
    }
    if(i<0 || j<0){
        return 1e9;
    }
    int up = grid[i][j] + solve1(i-1,j,grid);
    int left = grid[i][j] + solve1(i,j-1,grid);
    return min(up, left);
}
int minPathSum1(vector<vector<int>>& grid) {
    // Time complexity: O(2^(m+n))
    // space complexity: O(m*n)

    int m=grid.size();
    int n=grid[0].size();
    return solve1(m-1, n-1, grid);
}


// Memoization--------------------------------------------------------------------
int solve2(int i, int j, vector<vector<int>> grid, vector<vector<int>>&dp){
    // Base case 1: If we reach the destination (0, 0), return grid[0][0]
    if(i==0 && j==0){
        return grid[0][0];
    }
    // Base case 2: If we go out of bounds, there are no ways, not possible.
    if(i<0 || j<0){
        return 1e9;
    }

    // If we have already computed the number of ways for this cell, return it.
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Calculate the number of ways by moving up and left recursively.
    int up = grid[i][j] + solve2(i-1, j, grid, dp);
    int left = grid[i][j] + solve2(i, j-1, grid, dp);

    return dp[i][j]=min(up,left);
}
int minPathSum2(vector<vector<int>>grid) {
    // Time complexity:  O(N*M)
    // space complexity: O((M-1)+(N-1)) + O(N*M) We are using a recursion stack space: O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.

    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return solve2(m-1,n-1, grid, dp);
}


// Tabulation---------------------------------------------------------------------
int minPathSum3(vector<vector<int>>grid){
    // Time complexity: O(N*M)
    // space complexity: O(N*M)

    int m=grid.size();
    int n=grid[0].size();

    vector<vector<int>>dp(m, vector<int>(n, 0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=grid[0][0];
            }else{
                int up = INT_MAX, left = INT_MAX;
                if(i > 0){
                    up = grid[i][j] + dp[i-1][j];  // Check row bounds
                }
                if(j > 0){
                    left = grid[i][j] + dp[i][j-1]; // Check column bounds
                }
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[m-1][n-1]; 
}


// Space optimization------------------------------------------------------------
int minPathSum4(vector<vector<int>>grid){
    // time complexity: O(M*N)
    // space complexity: O(n)

    int m=grid.size();
    int n=grid[0].size();

    // Initialize a vector to store the previous row's minimum path sums
    vector<int>prev(n,0);
    for(int i=0;i<m;i++){
        // Initialize a temporary vector for the current row
        vector<int>temp(n,0);
        for(int j=0;j<n;j++){
            // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            if(i==0 && j==0){
                temp[j]=grid[0][0];
            }
            // Calculate the minimum path sum considering moving up and moving left
            else{
                // A large value if moving left or up is not possible (out of bounds)
                int up = INT_MAX, left = INT_MAX;
                // Include the minimum path sum from above (previous row)
                if(i > 0){
                    up = grid[i][j] + prev[j]; 
                }
                // Include the minimum path sum from the left (current row)
                if(j > 0){
                    left = grid[i][j] + temp[j-1]; 
                }
                // Store the minimum path sum in temp[j]
                temp[j] = min(up, left);
            }
        }
        // Update the previous row with the current row
        prev=temp;
    }
    // The final result is stored in prev[m-1], which represents the destination in the last column
    return prev[n-1];
}


int main(){
    vector<vector<int>>grid{
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    // Recursion
    cout<<minPathSum1(grid)<<endl;

    // Memoization - Better Approach: Memoization (Avoid Repeated Calculations)
    cout<<minPathSum2(grid)<<endl;

    // Tabulation - if we want to reduce the extra recursion stack space we use tabulation method
    cout<<minPathSum3(grid)<<endl;

    // space optimization - best solution
    cout<<minPathSum4(grid)<<endl;
}

