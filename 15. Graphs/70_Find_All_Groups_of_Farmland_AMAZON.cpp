#include<bits/stdc++.h>
using namespace std;


/* Q. Find All Groups of Farmland - AMAZON 2025

You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.


Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].


Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
Explanation: The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].


Input: land = [[0]]
Output: []
Explanation: There are no groups of farmland.

*/

void dfs(int i, int j, vector<vector<int>> &land, vector<vector<int>> &visited, int &minRow, int &minCol,int &maxRow, int &maxCol){

    int r = land.size();
    int c = land[0].size();

    visited[i][j] = 1;

    // Update rectangle bounds
    minRow = min(minRow, i);
    minCol = min(minCol, j);
    maxRow = max(maxRow, i);
    maxCol = max(maxCol, j);

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int d = 0; d < 4; d++){
        int nr = i + dx[d];
        int nc = j + dy[d];

        if (nr >= 0 && nr < r && nc >= 0 && nc < c && land[nr][nc] == 1 && !visited[nr][nc]){
            dfs(nr, nc, land, visited, minRow, minCol, maxRow, maxCol);
        }
    }
}

vector<vector<int>> findFarmland(vector<vector<int>> &land){
    int r = land.size();
    int c = land[0].size();

    vector<vector<int>> visited(r, vector<int>(c, 0));
    vector<vector<int>> result;

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (land[i][j] == 1 && !visited[i][j]){

                int minRow = i, minCol = j;
                int maxRow = i, maxCol = j;

                dfs(i, j, land, visited,minRow, minCol, maxRow, maxCol);

                result.push_back({minRow, minCol, maxRow, maxCol});
            }
        }
    }

    return result;
}

int main(){
    vector<vector<int>> land = {
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1}};
    vector<vector<int>>result = findFarmland(land);
    for(auto it: result){
        cout<<"[ ";
        for(auto it1: it){
            cout<<it1<<" ";
        }
        cout<<"]"<<" ";
    }
}