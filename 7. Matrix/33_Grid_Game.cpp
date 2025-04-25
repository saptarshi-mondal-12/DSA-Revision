#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Grid Game

You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.


Input: grid = [[2,5,4],[1,5,1]]
Output: 4
---------------------
🟥 2 | 🟥 5 |  4
---------------------
    1 | 🟥 5 | 🟥 1
---------------------

---------------------
🟦 0 | 🟦 0 | 🟦 4
---------------------
   1  |  0  |  🟦 0
---------------------

Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.


Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.


Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
*/

long long gridGame(vector<vector<int>>& grid) {
    long long n = grid[0].size();
    long long result=LLONG_MAX;

    // Computing Prefix sum for row1 and row 2
    vector<long long>prefixSum1(n,0);
    vector<long long>prefixSum2(n,0);

    prefixSum1[0]=grid[0][0];
    prefixSum2[0]=grid[1][0];

    for(int i=1;i<n;i++){
        prefixSum1[i] = prefixSum1[i-1] + grid[0][i];
        prefixSum2[i] = prefixSum2[i-1] + grid[1][i];
    }

    long long totalSum1=prefixSum1[n-1];
    long long bottom=0;

    for (int i = 0; i < n; i++) {
        // Robot 1 switches at column i
        long long topRemaining = totalSum1 - prefixSum1[i];
        long long bottomRemaining = bottom;
        bottom+=grid[1][i];
        long long secondRobotScore = max(topRemaining, bottomRemaining);

        // first roboot want to minizie point for 2nd robot 
        result = min(result, secondRobotScore);
    }
    return result;
}

int main(){
    vector<vector<int>> grid1 = {{2,5,4},{1,5,1}};
    vector<vector<int>> grid2 = {{3,3,1},{8,5,2}};
    vector<vector<int>> grid3 = {{1,3,1,15},{1,3,3,1}};

    cout << gridGame(grid1) << endl; // Output: 4
    cout << gridGame(grid2) << endl; // Output: 4
    cout << gridGame(grid3) << endl; // Output: 7

    return 0;

}