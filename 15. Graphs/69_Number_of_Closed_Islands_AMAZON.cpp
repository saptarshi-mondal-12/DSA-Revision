#include <bits/stdc++.h>
using namespace std;

/* Q. Number of Closed Islands - AMAZON 2025

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.


Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: Islands in gray are closed because they are completely surrounded by water (group of 1s).

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

*/

bool dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
    int r = grid.size();
    int c = grid[0].size();

    // If land touches boundary → not a closed island
    if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
        return false;

    visited[i][j] = 1;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isClosed = true;

    for (int dir = 0; dir < 4; dir++){
        int newRow = i + dx[dir];
        int newCol = j + dy[dir];

        if (newRow >= 0 && newRow < r && newCol >= 0 && newCol < c){
            if (!visited[newRow][newCol] && grid[newRow][newCol] == 0)
            {
                isClosed = dfs(newRow, newCol, grid, visited) && isClosed;
            }
        }
    }

    return isClosed;
}
int closedIsland(vector<vector<int>> &grid){
    // Time Complexity: O(r*c) = Each cell is visited once using DFS, so the time complexity is O(R×C)
    // Space Complexity: O(r*c) = We use a visited matrix and recursion stack, leading to O(R×C) auxiliary space.

    /*  Each cell in the grid is visited at most once.
        DFS marks a cell as visited, so it is never processed again.
        For each land cell (0), we explore up to 4 directions (constant work).
        Therefore: Total operations ≤ R × C × 4  →  O(R × C)
    */

    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> visited(r, vector<int>(c, 0));

    int noOfClosedIslands = 0;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            // if it is a land i.e 0 and not visited do a dfs.
            if (grid[i][j] == 0 && !visited[i][j]){
                if (dfs(i, j, grid, visited)){
                    noOfClosedIslands++;
                }
            }
        }
    }

    return noOfClosedIslands;
}

int main(){
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };

    cout << "Number of Closed Islands: " << closedIsland(grid) << endl;

    return 0;
}