#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Find the number of islands

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.


Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
Output: 4

Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
Output: 2
*/

void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &visited, int baseRow, int baseCol){
    visited[row][col] = 1;

    int n = grid.size();
    int m = grid[0].size();

    // Traversing all 8 directions
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < 8; i++){
        int r = row + dr[i];
        int c = col + dc[i];

        if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 'L' && !visited[r][c]){
            visited[r][c] = 1;
            dfs(r, c, grid, visited, baseRow, baseCol);
        }
    }
}
int countIslands(vector<vector<char>> &grid){
    // Code here
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int islandCount = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j] && grid[i][j] == 'L'){
                int baseRow = i, baseCol = j;
                dfs(i, j, grid, visited, baseRow, baseCol);
                islandCount++;
            }
        }
    }
    return islandCount;
}

int main(){
    vector<vector<char>> grid = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };

    int result = countIslands(grid);
    cout << "Number of islands: " << result << endl;
}