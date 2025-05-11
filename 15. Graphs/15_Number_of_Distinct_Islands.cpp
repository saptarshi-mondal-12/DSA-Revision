#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Number of Distinct Islands

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output: 1
Explanation:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Same colored islands are equal. We have 2 equal islands, so we have only 1 distinct island.


Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output: 3
Explanation:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Same colored islands are equal. We have 4 islands, but 2 of them are equal, So we have 3 distinct islands.

*/

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &vec, int baseRow, int baseCol){
    visited[row][col] = 1;
    vec.push_back({row - baseRow, col - baseCol});

    int n = grid.size();
    int m = grid[0].size();

    // Traversing all 4 directions
    int r = row - 1, c = col;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        visited[r][c] = 1;
        dfs(r, c, grid, visited, vec, baseRow, baseCol);
    }
    r = row, c = col + 1;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        visited[r][c] = 1;
        dfs(r, c, grid, visited, vec, baseRow, baseCol);
    }
    r = row + 1, c = col;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        visited[r][c] = 1;
        dfs(r, c, grid, visited, vec, baseRow, baseCol);
    }
    r = row, c = col - 1;
    if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !visited[r][c]){
        visited[r][c] = 1;
        dfs(r, c, grid, visited, vec, baseRow, baseCol);
    }
}
int countDistinctIslands(vector<vector<int>> &grid){
    // Time complexity: O(nxm) + O(nxmx4) = O(nxm)
    // space complexity: O(nxm) + O(nxm) + O(nxm) = O(nxm)

    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j] && grid[i][j] == 1){
                vector<pair<int, int>> vec;
                int baseRow = i, baseCol = j;
                dfs(i, j, grid, visited, vec, baseRow, baseCol);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main(){
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};

    cout<<countDistinctIslands(grid);
}