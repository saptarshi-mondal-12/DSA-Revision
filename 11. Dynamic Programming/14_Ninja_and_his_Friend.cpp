#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Ninja and his friend

You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:
    Robot #1 is located at the top-left corner (0, 0), and
    Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:
    From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
    When both robots stay in the same cell, only one takes the cherries.
    Both robots cannot move outside of the grid at any moment.
    Both robots should reach the bottom row in grid.

Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.



Intuition : 
In this question, there are two fixed starting and variable ending points, but as per the movement of Alice and Bob, we know that they will end in the last row. They have to move together at a time to the next row.

Why a Greedy Solution doesn’t work?

As we have to return the maximum chocolates collected, the first approach that comes to our mind is to take a greedy approach and always form a path by locally choosing the option that gives us more chocolates. But there is no ‘uniformity’ in the values of the matrix, therefore it can happen that whenever we are making a local choice that gives us a better path, we actually take a path that in the later stages is giving us fewer chocolates.

As a greedy solution doesn’t work, our next choice will be to try out all the possible paths. To generate all possible paths we will use recursion.

All paths by robot#1 + All paths by robot#2 together whatever is the maximum will be my answer.

NOTE: robot#1 and robot#2 move together simultaneously. It might there is a common cell that robot#1 and robot#2 passes. So for that cell we have to considerd it only at once. Write recursion together.

Rule: 
1. Express everything in term of index (i1,j1) & (i2,j2), robot#1 and robot#2 respectively.
2. Explore all paths - bottom, left, right.
3. return maximum  

Both will reach destination same time -> Movements, no matter which column, at every step we go to next row (i+1) be it robot#1 or robot#2. We will move to next row sure. I can say instead of maintaining i1 & i2, can I write single i? 
Yes we can because both robot can move simultaneously and row remoain same for bith robot (i will be same, column different for both robot). so (i, j1, j2, r, c, grid)  

Explore all that: 
In one step move robot#1 & robot#2 both because we writing recursion for both
[*, *  , *, *, *]
[*, R1 , *, R2, *]
[#,  * , @,  @, @]
[*,  * , *, *, *]

Suppose R1 can move left(i+1, j-1) mark with #.
And R2 can either move left(i+1,j-1) either move bottom(i+1,j) or either move right(i+1,j+1) mark with @. 
So for 1 movement of robot#1 , robot#2 can move an of other movements

Together the can move like this (R1 and R2) or (R1 and R2) or (R1 and R2) 
                                /       /       /       |      /       \

for eyery 3 movement of robot#1 i can say robot#2 has also 3 simultaneous movement . 
In total 3*3=9 combos of path that i have to try
Solution : for j can be  [-1, 0, +1](column change every time). Using 2 for i=loop (0->2) and j=(0->2)

------------------- Algorithm: ---------------------------------------------
Step 1: Express the problem in terms of indexes.

This question is slightly different from all the previous questions, here we are given two starting points from where Alice and Bob can move.
We are given an ‘N*M’ matrix. We need to define the function with four parameters  i1,j1,i2, and j2 to describe the positions of Alice and Bob at a time.
If we observe, initially Alice and Bob are at the first row, and they always move to the row below them every time, so they will always be in the same row. Therefore two different variables i1 and i2, to describe their positions are redundant. We can just use single parameter i, which tells us in which row of the grid both of them are.

Therefore, we can modify the function. It now takes three parameters: i,j1, and j2. f(i,j1,j2) will give us the maximum number of chocolates collected by Alice and Bob from their current positions to the last position.

Base Case: There will be the following base cases:

When i == N-1, it means we are at the last row, so we need to return from here. Now it can happen that at the last row, both Alice and Bob are at the same cell, in this condition we will return only chocolates collected by Alice, mat[i][j1]( as question states that the chocolates cannot be doubly calculated), otherwise we return sum of chocolates collected by both, mat[i][j1] + mat[i][j1][j2].
At every cell, we have three options to go: to the bottom cell (↓), to the bottom-right cell(↘) or to the bottom-left cell(↙)

As we are moving to the bottom cell (↓), at max we will reach the last row, from where we return, so we will never go out of the bounding index.

To move to the bottom-right cell(↘) or to the bottom-left cell(↙), it can happen that we may go out of bound as shown in the figure(below). So we need to handle it, we can return -1e9, whenever we go out of bound, in this way this path will not be selected by the calling function as we have to return the maximum chocolates.

If j1<0 or j1>=M or j2<0 or j2>=M  , then we return -1e9 

Step 2: Try out all possible choices at a given index.
At every cell, we have three options to go: to the bottom cell (↓), to the bottom-right cell(↘) or to the bottom-left cell(↙)
Now, we need to understand that we want to move Alice and Bob together. Both of them can individually move three moves but say Alice moves to bottom-left, then Bob can have three different moves for Alice’s move, and so on. 
Hence we have a total of 9 different options at every f(i,j1,j2) to move Alice and Bob. Now we can manually write these 9 options or we can observe a pattern in them, first Alice moves to one side and Bob tries all three choices, then again Alice moves, then Bob, and so on. This pattern can be easily captured by using two nested loops that change the column numbers(j1 and j2).

Note: if (j1===j2), as discussed in the base case, we will only consider chocolates collected by one of them otherwise we will consider chocolates collected by both of them.

Step 3:  Take the maximum of all choices
As we have to find the maximum chocolates collected of all the possible paths, we will return the maximum of all the choices(the 9 choices of step 2). We will take a maxi variable( initialized to INT_MIN). We will update maxi to the maximum of the previous maxi and the answer of the current choice. At last, we will return maxi from our function as the answer.


Space optimization - 
If we look closely, to compute dp[i][j1][j2], we need values only from dp[i+1][][]. Therefore it is not necessary to store a three-dimensional array. Instead, we can store a two-dimensional array and update it as we move from one plane to the other in the 3D Array.

*/

// Recursion-------------------------------------------------------------------------------------
int solve1(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid){
    // Base case 1: check if the paths are invalid i.e grid bounderies
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
        return -1e8;
    }
    // Base case 2: If we are at the last row, return the chocolate at the positions (j1, j2)
    if (i == r-1) {
        // if both robot are on same column, then pick 1 
        if (j1 == j2){
            return grid[i][j1];
        }
        else{ // if both robot are on different column, then pick both
            return grid[i][j1] + grid[i][j2];
        }
    }

    int maxi = INT_MIN;

    // Explore all paths (down left right) for both positions (j1, j2).
    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            int ans;
            // if both robot are at same cell just add it one and call for next path
            if (j1 == j2)
                ans = grid[i][j1] + solve1(i + 1, j1 + di, j2 + dj, r, c, grid);
            else // if both are not on same cell then robot#1 cell + robot#2 cell gets added to same function call
                ans = grid[i][j1] + grid[i][j2] + solve1(i + 1, j1 + di, j2 + dj, r, c, grid);
            // Update the maximum result
            maxi = max(maxi, ans);
        }
    }
    // return the  maximum
    return maxi;
}
int cherryPickup1(vector<vector<int>>& grid) {
    /*Time complexity: O(r*c*c*9)
    At max, there will be r*c*c calls of recursion to solve a new problem and in every call, two nested loops together run for 9 times.

    The function solve1(i, j1, j2, r, c, grid) represents:
        i → Current row (0 to r−1)
        j1 → Column of Robot#1 (0 to c−1)
        j2 → Column of Robot#2 (0 to c−1)
    Each robot can move in three directions (left, down, right).Since there are two robots, we have a total of 3×3=9 transitions for every recursive call i.e O(r×c×c)×O(9)

    Space complexity: O(r)) + O(r*c*c)
    */

    int r=grid.size();
    int c=grid[0].size();

    // robot#1 starting (0,0) i.e (i,j1) ad robot#2 starting (0, c-1) i.e (i,j2). 
    // splve1(i, j1, j2, r, c, rid)
    return solve1(0,0,c-1,r,c,grid);
}



// Memoization ----------------------------------------------------------------------------------
int solve2(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp){
    // Base case 1: check if the positions are invalid i.e grid bounderies
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
        return -1e8;
    }
    // Base case 2: If we are at the last row, return the chocolate at the positions (j1, j2)
    if (i == r-1) {
        // if both robot are on same column, then pick 1 
        if (j1 == j2){
            return grid[i][j1];
        }
        else{ // if both robot are on different column, then pick both
            return grid[i][j1] + grid[i][j2];
        }
    }

    // If the result for this state is already computed, return it
    if (dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    int maxi = INT_MIN;

    // Explore all paths (down left right) for both positions (j1, j2).
    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + solve2(i + 1, j1 + di, j2 + dj, r, c, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + solve2(i + 1, j1 + di, j2 + dj, r, c, grid, dp);
            
            // Update the maximum result
            maxi = max(maxi, ans);
        }
    }

    // Store the maximum result for this state in dp
    return dp[i][j1][j2] = maxi;
}
int cherryPickup2(vector<vector<int>>& grid) {
    // Time complexity:  O(r*c*c) * 9
    // Space complexity:  O(r) + O(r*c*c) We are using a recursion stack space: O(r), where r is the path length and an external DP Array of size ‘r*c*c’.

    int r=grid.size();
    int c=grid[0].size();

    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve2(0,0,c-1,r,c,grid, dp);
}



// Tabulation ----------------------------------------------------------------------------------
int cherryPickup3(vector<vector<int>>& grid) {
    // Time complexity:  O(r*c*c) * 9
    // Space complexity: O(r*c*c)

    int r=grid.size();
    int c=grid[0].size();

    // Note: opposite of recursion i.e. last row to first row

    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>>dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    // Initialize the DP array for the last row
    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    // First loop -> row (r-2 -> 0)
    // second loop -> robot#1 column  (0 -> c-1)
    // third loop -> robot#2 column  (0 -> c-1)
    for (int i = r - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= c) || (j2 + dj < 0 || j2 + dj >= c))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj]; // Include the DP result from the next row

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                dp[i][j1][j2] = maxi; // Store the maximum result for this state in the DP array
            }
        }
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return dp[0][0][c - 1];
}



// Space optimization---------------------------------------------------------------
int cherryPickup4(vector<vector<int>>& grid) {
    // Time complexity:  O(r*c*c) * 9
    // Space complexity: O(c*c)

    int r=grid.size();
    int c=grid[0].size();

    // Create a 2D DP array to store computed results
    vector<vector<int>>prev(c, vector<int>(c,0));
    vector<vector<int>>curr(c, vector<int>(c,0));

    // Initialize the DP array for the last row
    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2)
                prev[j1][j2] = grid[r - 1][j1];
            else
                prev[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    // Outer nested loops for traversing the DP array from the second-to-last row up to the first row
    for (int i = r - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                int maxi = INT_MIN;

                // Inner nested loops to try out 9 options (diagonal moves)
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        // Check if the move is valid (within the grid boundaries)
                        if ((j1 + di < 0 || j1 + di >= c) || (j2 + dj < 0 || j2 + dj >= c))
                            ans += -1e9; // A very large negative value to represent an invalid move
                        else
                            ans += prev[j1 + di][j2 + dj]; // Include the DP result from the next row

                        maxi = max(ans, maxi); // Update the maximum result
                    }
                }
                curr[j1][j2] = maxi; // Store the maximum result for this state in the DP array
            }
        }
        prev=curr;
    }

    // The maximum chocolates that can be collected is stored at the top-left corner of the DP array
    return prev[0][c - 1];
}



int main(){
    vector<vector<int>>grid={
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };

    // Recursion - time limit exceed
    cout<<cherryPickup1(grid)<<endl;

    // Memoization - use dp to reduce repetetive calculation
    cout<<cherryPickup2(grid)<<endl;

    // Tabulation - reduce the extra recursion stack space 
    cout<<cherryPickup3(grid)<<endl;

    // space optimization - best space optimal solution
    cout<<cherryPickup4(grid)<<endl;
}

