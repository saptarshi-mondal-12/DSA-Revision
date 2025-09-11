#include <bits/stdc++.h>
using namespace std;

/* Q. Max Area of Island - AMAZON 2025

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.



Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

*/

int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
    visited[i][j] = 1;

    queue<pair<int, int>> q;
    q.push({i, j});
    int count = 0;

    int row = grid.size();
    int col = grid[0].size();

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    while (!q.empty()){
        int adj_row=q.front().first;
        int adj_col=q.front().second;
        q.pop();
        count++;

        for (int dir = 0; dir < 4; dir++){
            int newRow = adj_row + dr[dir];
            int newCol = adj_col + dc[dir];

            if (newRow >= 0 && newRow < row &&
                newCol >= 0 && newCol < col &&
                grid[newRow][newCol] == 1 &&
                !visited[newRow][newCol])
            {
                q.push({newRow, newCol});
                visited[newRow][newCol] = 1;
            }
        }
    }
    return count;
}

int maxAreaOfIsland(vector<vector<int>> &grid){
    // Time complexity: O(row x col)
    // space complexity: O(row x col)


    int row = grid.size();
    int col = grid[0].size();

    int result = 0;
    vector<vector<int>> visited(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (!visited[i][j] && grid[i][j] == 1){
                int area = bfs(i, j, grid, visited);
                result = max(result, area);
            }
        }
    }
    return result;
}

int main(){
}
