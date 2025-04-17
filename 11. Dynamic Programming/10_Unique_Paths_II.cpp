#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Unique Paths || 

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 10^9.

-------------
| S |   |   | 
-------------
|   | -1 |   | 
-------------
|   |   | E |  
-------------

S = START (grid[0][0])
E = END (grid[m - 1][n - 1])
-1 = BLOCK

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Intuition: Same code Unique Paths 

A path through the cell[1][1] is not possible as it is blocked, therefore we need to count every other legit path which doesn’t include the cell[1][1].
Add base case: if(i>=0 && j>=0 && mat[i][j]==-1) return 0;

Base Case: There will be three base cases:
    1. When i>0 and j>0 and mat[i][j] = -1, it means that the current cell is an obstacle, so we can’t find a path from here. Therefore, we return 0.

    2. When i=0 and j=0, that is we have reached the destination so we can count the current path that is going on, hence we return 1.
    
    3. When i<0 and j<0, it means that we have crossed the boundary of the matrix and we couldn’t find a right path, hence we return 0.
*/

// Recursion----------------------------------------------------------------------
int solve1(int i, int j, vector<vector<int>> &maze){ 
    // Base case 1: If there's an obstacle at (i, j), return 0
    if (i >= 0 && j >= 0 && maze[i][j] == -1){
        return 0;
    }
    // Base case 2: If we reach the destination (0, 0), return 1
    if(i==0 && j==0){
        return 1;
    }
    // Base case 3: If we go out of bounds, there are no ways, not possible.
    if(i<0 || j<0){
        return 0;
    }
    // Calculate the number of ways by moving up and left recursively.
    int up = solve1(i-1,j, maze);
    int left = solve1(i,j-1, maze);

    // count all the possible unique paths, we will return the sum of the choices(up and left) 
    return up+left;
}
int uniquePaths1(int m, int n, vector<vector<int>> maze) {
    // Time complexity: O(2^(m*n)) for every box we are taking 2 paths (up left up left........) which is exponential.
    // space complexity: O((N-1)+(M-1)) path length

    return solve1(m-1,n-1, maze);
}


// Memoization--------------------------------------------------------------------
int solve2(int i, int j, vector<vector<int>> maze, vector<vector<int>>&dp){
    // Base case 1: If there's an obstacle at (i, j), return 0
    if (i >= 0 && j >= 0 && maze[i][j] == -1){
        return 0;
    }
    // Base case 2: If we reach the destination (0, 0), return 1
    if(i==0 && j==0){
        return 1;
    }
    // Base case 3: If we go out of bounds, there are no ways, not possible.
    if(i<0 || j<0){
        return 0;
    }

    // If we have already computed the number of ways for this cell, return it.
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Calculate the number of ways by moving up and left recursively.
    int up = solve2(i-1, j, maze, dp);
    int left = solve2(i, j-1, maze, dp);

    // count all the possible unique paths, we will return the sum of the choices(up and left) 
    return dp[i][j]=up+left;
}
int uniquePaths2(int m, int n, vector<vector<int>> maze) {
    // Time complexity: O(m*n)
    // space complexity: O((N-1)+(M-1)) + O(M*N)

    vector<vector<int>> dp(m, vector<int>(n,-1));
    return solve2(m-1,n-1, maze, dp);
}


// Tabulation---------------------------------------------------------------------
int uniquePaths3(int m, int n, vector<vector<int>> maze){
    // Time complexity: O(m*n)
    // space complexity: O(m*n)

    vector<vector<int>> dp(m, vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (i >= 0 && j >= 0 && maze[i][j] == -1) {
                dp[i][j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            // Base condition: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; // Skip the rest of the loop and continue with the next iteration.
            }

            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the cell above.
            if (i > 0)
                up = dp[i - 1][j];

            // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
            if (j > 0)
                left = dp[i][j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}


// Space optimization------------------------------------------------------------
int uniquePaths4(int m, int n, vector<vector<int>> maze){
    // time complexity: O(m*n)
    // space complexity: O(n)

    // Create a vector to represent the previous row of the grid.
    vector<int>prev(n,0);
    for(int i=0;i<m;i++){
        // Create a temporary vector to represent the current row.
        vector<int> temp(n, 0);

        for(int j=0;j<n;j++){
            // Base case 1: 
            if (i >= 0 && j >= 0 && maze[i][j] == -1) {
                temp[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
                continue;
            }
            // Base case 2: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue; 
            }
            // Initialize variables to store the number of ways from the cell above (up) and left (left).
            int up = 0;
            int left = 0;

            // If we are not at the first row (i > 0), update 'up' with the value from the previous row.
            if (i > 0)
                up = prev[j];

            // If we are not at the first column (j > 0), update 'left' with the value from the current row.
            if (j > 0)
                left = temp[j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            temp[j] = up + left;
        }
        // Update the previous row with the values calculated for the current row.
        prev=temp;
    }
    return prev[n-1];
}


int main(){
    int m=3, n=3;
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };

    // Recursion
    cout<<uniquePaths1(m,n,maze)<<endl;

    // Memoization - if there are overlapping sub problems we apply memoization
    cout<<uniquePaths2(m,n,maze)<<endl;

    // Tabulation - if we want to reduce the extra recursion stack space we use tabulation method
    cout<<uniquePaths3(m,n,maze)<<endl;

    // space optimization - best solution
    cout<<uniquePaths4(m,n,maze)<<endl;
}

