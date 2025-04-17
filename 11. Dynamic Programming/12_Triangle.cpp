#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Triangle

Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10

Intuition: 
This question is a slight modification of the question discussed in Minimum Path Sum in a Grid. In the previous problem, we were given a rectangular matrix whereas here the matrix is in the form of a triangle. Moreover, we don’t have a fixed destination(at last row we have variable desitnation either 4, either 1 or 8 or 3) we need to return the minimum sum path from the top cell to any cell of the bottom row.

Q. Why a Greedy Solution doesn’t work?
As we have to return the minimum path sum, the first approach that comes to our mind is to take a greedy approach and always form a path by locally choosing the cheaper option.

1
2 3
3 1 7
0 9 6 10

At every cell, we have two choices: to move to the bottom cell or move to the bottom-right cell. Our ultimate aim is to provide a path that provides us the least path sum. Therefore at every cell, we will make the choice to move which costs us less.

    Greedy solution path = (0,0) + (1,0) + (2,1) + (3,2) = 1+2+1+6=10
    Non-greedy path = (0,0) + (1,0) + (2,0) + (3,0) = 1+2+3+0=6

We can clearly see the problem with the greedy solution. Whenever we are making a local choice, we may tend to choose a path that may cost us way more later.

Therefore, the other alternative left to us is to generate all the possible paths and see which is the path with the minimum path sum. To generate all paths we will use recursion.

-----------------recursive solution: 
We are given a triangular matrix with the number of rows equal to N.

We can define the function with two parameters i and j, where i and j represent the row and column of the matrix.

Now our ultimate aim is to reach the last row. We can define f(i,j) such that it gives us the minimum path sum from the cell [i][j] to the last row.
We want to find f(0,0) and return it as our answer.

Base Case:
There will be a single base case:
    When i == N-1, that is when we have reached the last row, so the min path from that cell to the last row will be the value of that cell itself, hence we return mat[i][j].

At every cell, we have two options to move to the bottom cell(↓) or to the bottom-right cell(↘). If we closely observe the triangular grid, at max we can reach the last row from where we return so we will not be able to go move out of the index of the grid. Therefore only one base condition is required.

Step 2: Try out all possible choices at a given index.

At every index we have two choices, one to go to the bottom cell(↓) other to the bottom-right cell(↘). To go to the bottom, we will increase i by 1, and to move towards the bottom-right we will increase both i and j by 1.

Now when we get our answer for the recursive call (f(i+1,j) or f(i+1,j+1)), we need to also add the current cell value to it as we have to include it too for the current path sum.


Step 3:  Take the minimum of all choices
As we have to find the minimum path sum of all the possible unique paths, we will return the minimum of the choices(down and diagonal)

--------------------Tabulation solution
Recursion/Memoization is a top-down approach whereas tabulation is a bottom-up approach. As in recursion/memoization, we have moved from 0 to N-1, in tabulation we move from N-1 to 0, i.e the last row to the first one.

    1. Declare a dp[] array of size [N][N].

    2. First initialize the base condition values, i.e the last row of the dp matrix to the last row of the triangle matrix.

    3. Our answer should get stored in dp[0][0]. We want to move from the last row to the first row. So that whenever we compute values for a cell, we have all the values required to calculate it.

    4. If we see the memoized code, the values required for dp[i][j] are dp[i+1][j] and dp[i+1][j+1]. So we only need the values from the ‘i+1’ row.

    5. We have already filled the last row (i=N-1), if we start from row ‘N-2’ and move upwards we will find the values correctly.
    
    6. We can use two nested loops to have this traversal.


---------------Space optimize
If we closely look the relation, dp[i][j] = matrix[i][j] + min(dp[i+1][j] + dp[i+1][j+1]))
We see that we only need the next row, in order to calculate dp[i][j]. Therefore we can space optimize it.

*/

// Recursion - Time limit exceed ------------------------------------------------------------
int solve1(int i, int j, int n, vector<vector<int>>&triangle){
    // If we're at the bottom row i.e last row, return the value of the current cell
    if(i==n-1){
        return triangle[i][j];
    }
    int down = triangle[i][j] + solve1(i+1, j, n, triangle);
    int diagonal = triangle[i][j] + solve1(i+1, j+1, n, triangle);

    return min(down, diagonal);
}
int minimumTotal1(vector<vector<int>>& triangle) {
    // Time complexity: O(2^n) exponential growth. no of rows = row_1 col_1 + row_2 col_2 +......row_n col_n. Each for every column we have couple of options down or bottom. so 2*2*2......n

    // space complexity: O(n) - recursion stack space 

    int n=triangle.size();
    return solve1(0,0,n,triangle);
}


// Memoization-------------------------------------------------------------------------------
int solve2(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp){
    // If we're at the bottom row i.e last row, return the value of the current cell
    if(i==n-1){
        return triangle[i][j];
    }

    // If the result for this cell is already calculated, return it
    if(dp[i][j] != -1) return dp[i][j];

    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + solve2(i+1, j, n, triangle, dp);
    int diagonal = triangle[i][j] + solve2(i+1, j+1, n, triangle, dp);

    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j]=min(down, diagonal);
}
int minimumTotal2(vector<vector<int>>& triangle) {
    // Time complexity: O(n*n)
    // space complexity: O(n) + O(n*n) we are using an dp of size n*n

    int n=triangle.size();
    vector<vector<int>>dp(n, vector<int>(n,-1));
    return solve2(0,0,n,triangle, dp);
}


// Tabulation - Reducing external stack space-----------------------------------------------
int minimumTotal3(vector<vector<int>>& triangle){
    // Time complexity: O(n*n)
    // space complexity: O(n*n)

    int n=triangle.size();
    vector<vector<int>>dp(n, vector<int>(n,-1));

    // Initialize the bottom row of dp with the values from the triangle
    for(int j=0;j<n;j++){
        dp[n-1][j]=triangle[n-1][j];
    }
    // Iterate through the triangle rows in reverse order
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }
    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}


// space optimization ----------------------------------------------------------------------
int minimumTotal4(vector<vector<int>>& triangle){
    // Time complexity: O(n*n)
    // space complexity: O(n)

    int n=triangle.size();

    // Represents the previous row
    vector<int>prev(n,0);

    // Initialize the front array with values from the last row of the triangle
    for(int j=0;j<n;j++){
        prev[j]=triangle[n-1][j];
    }

    // Iterate through the triangle rows in reverse order
    for(int i=n-2; i>=0; i--){
        // Represents the current row
        vector<int>curr(n,0);
        for(int j=i; j>=0; j--){
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + prev[j];
            int diagonal = triangle[i][j] + prev[j + 1];

            // Store the minimum of the two possible paths in dp
            curr[j] = min(down, diagonal);
        }
        // Update the prev array with the values from the current row
        prev=curr;
    }
    // The prev array now contains the minimum path sum from the top to the bottom of the triangle
    return prev[0];
}

int main(){
    vector<vector<int>>triangle{
        {1},
        {2,3},
        {3,1,7},
        {0,9,6,10}
    };

    // Recursion
    cout<<minimumTotal1(triangle)<<endl;

    // Memoization - Better Approach: Memoization (Avoid Repeated Calculations)
    cout<<minimumTotal2(triangle)<<endl;

    // Tabulation - if we want to reduce the extra recursion stack space we use tabulation method
    cout<<minimumTotal3(triangle)<<endl;

    // space optimization - best solution
    cout<<minimumTotal4(triangle)<<endl;

}

