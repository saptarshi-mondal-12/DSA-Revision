#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

-----------------------------
| S |   |   |   |   |   |   |
-----------------------------
|   |   |   |   |   |   |   |
-----------------------------
|   |   |   |   |   |   | E |
-----------------------------

S = START (grid[0][0])
E = END (grid[m - 1][n - 1])

Input: m = 3, n = 7
Output: 28

Inutuition: 
As we have to count all possible ways to go from matrix[0,0] to matrix[m-1,n-1], we can try recursion to generate all possible paths.

Step 1: Express the problem in terms of indexes.
We are given two variables M and N, representing the dimensions of a 2D matrix. For every different problem, this M and N will change. We can define the function with two parameters i and j, where i and j represent the row and column of the matrix.

f(i,j) = total amount of unique paths from matrix[0][0] to matix[i][j].

We will be doing a top-down recursion, i.e we will move from the cell[M-1][N-1] and try to find our way to the cell[0][0]. Therefore at every index, we will try to move up and towards the left.

Base Case:
    1. When i=0 and j=0, that is we have reached the destination so we can count the current path that is going on, hence we return 1.
    
    2.When i<0 and j<0, it means that we have crossed the boundary of the matrix and we couldn’t find a right path, hence we return 0.


Step 2: Try out all possible choices at a given index.
As we are writing a top-down recursion, at every index we have two choices, one to go up(↑) and the other to go left(←). To go upwards, we will reduce i by 1, and move towards left we will reduce j by 1.

Step 3:  Take the maximum of all choices
As we have to count all the possible unique paths, we will return the sum of the choices(up and left) 

Tabulation: 
Our answer should get stored in dp[m-1][n-1]. We want to move from (0,0) to (m-1,n-1). But we can’t move arbitrarily, we should move such that at a particular i and j, we have all the values required to compute dp[i][j].
If we see the memoized code, the values required for dp[i][j] are dp[i-1][j] and dp[i][j-1]. So we only use the previous row and column value.
We have already filled the top-left corner (i=0 and j=0), if we move in any of the two following ways(given below), at every cell we do have all the previous values required to compute its value.

Space Optimization:
If we closely look at the relationship,

dp[i][j] = dp[i-1][j] + dp[i][j-1])

We see that we only need the previous row and column, in order to calculate dp[i][j]. Therefore we can space optimize it.
Initially, we can take a dummy row ( say prev) and initialize it as 0.
Now the current row(say temp) only needs the previous row value and the current row’s value in order to calculate dp[i][j]. At the next step, the temp array becomes the prev of the next step and using its values we can still calculate the next row’s values.
At last prev[n-1] will give us the required answer.

*/

// Recursion----------------------------------------------------------------------
int solve1(int i, int j){
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if(i==0 && j==0){
        return 1;
    }
    // If we go out of bounds, there are no ways, not possible.
    if(i<0 || j<0){
        return 0;
    }
    // Calculate the number of ways by moving up and left recursively.
    int up = solve1(i-1,j);
    int left = solve1(i,j-1);

    // count all the possible unique paths, we will return the sum of the choices(up and left) 
    return up+left;
}
int uniquePaths1(int m, int n) {
    // Time complexity: O(2^(m*n)) for every box we are taking 2 paths (up left up left........) which is exponential.
    // space complexity: O((N-1)+(M-1)) path length

    return solve1(m-1,n-1);
}


// Memoization--------------------------------------------------------------------
int solve2(int i, int j, vector<vector<int>>&dp){
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if(i==0 && j==0){
        return 1;
    }
    // If we go out of bounds, there are no ways.
    if(i<0 || j<0){
        return 0;
    }
    // If we have already computed the number of ways for this cell, return it.
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // Calculate the number of ways by moving up and left recursively.
    int up = solve2(i-1,j,dp);
    int left = solve2(i,j-1,dp);

    // count all the possible unique paths, we will return the sum of the choices(up and left) 
    return dp[i][j]=up+left;
}
int uniquePaths2(int m, int n) {
    // Time complexity: O(m*n)
    // space complexity: O((N-1)+(M-1)) + O(M*N)

    vector<vector<int>> dp(m, vector<int>(n,-1));
    return solve2(m-1,n-1,dp);
}


// Tabulation---------------------------------------------------------------------
int uniquePaths3(int m, int n){
    // Time complexity: O(m*n)
    // space complexity: O(m*n)

    vector<vector<int>> dp(m, vector<int>(n,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
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
int uniquePaths4(int m, int n){
    // time complexity: O(m*n)
    // space complexity: O(n)

    // Create a vector to represent the previous row of the grid.
    vector<int>prev(n,0);
    for(int i=0;i<m;i++){
        // Create a temporary vector to represent the current row.
        vector<int> temp(n, 0);

        for(int j=0;j<n;j++){
            // Base case: If we are at the top-left cell (0, 0), there is one way.
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
    int m=3, n=7;

    // Recursion
    cout<<uniquePaths1(m,n)<<endl;

    // Memoization - if there are overlapping sub problems we apply memoization
    cout<<uniquePaths2(m,n)<<endl;

    // Tabulation - if we want to reduce the extra recursion stack space we use tabulation method
    cout<<uniquePaths3(m,n)<<endl;

    // space optimization - best solution
    cout<<uniquePaths4(m,n)<<endl;
}

