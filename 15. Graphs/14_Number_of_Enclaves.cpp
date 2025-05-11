#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Number of Enclaves

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


Input: grid = [
    [0,0,0,0],
    [1,0,1,0],
    [0,1,1,0],
    [0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.


Intuition:--------------------------------------------------------------------------------

1 surrounded with 0 (all 4 directions) are only considered. 

The land cells present in the boundary cannot be counted in the answer as we will walk off the boundary of the grid. Also, land cells connected to the boundary land cell can never be the answer. 

The intuition is that we need to figure out the boundary land cells, go through their connected land cells and mark them as visited. The sum of all the remaining land cells will be the answer.

*/



void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid){
    visited[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    // Traversing all 4 direction (up, right, down, left)
    int r = row - 1, c = col;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        dfs(r, c, visited, grid);
    }

    r = row, c = col + 1;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        dfs(r, c, visited, grid);
    }

    r = row + 1, c = col;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        dfs(r, c, visited, grid);
    }

    r = row, c = col - 1;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        dfs(r, c, visited, grid);
    }
}
int numEnclaves(vector<vector<int>> &grid){
    // Time complexity: O(m) + O(n) + O(nxmx4)
    // Space complexity: O(nxm) + O(nxm)

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Traversing first row and last row
    for (int j = 0; j < m; j++){
        // first row
        if (grid[0][j] == 1){
            dfs(0, j, visited, grid);
        }

        // last row
        if (grid[n - 1][j] == 1){
            dfs(n - 1, j, visited, grid);
        }
    }

    // Traversing first col and last col
    for (int i = 0; i < n; i++){
        // first row
        if (grid[i][0] == 1){
            dfs(i, 0, visited, grid);
        }

        // last row
        if (grid[i][m - 1] == 1){
            dfs(i, m - 1, visited, grid);
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1 && !visited[i][j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
    cout<<numEnclaves(grid);
}