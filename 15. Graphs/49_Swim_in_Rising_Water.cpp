#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Swim in Rising Water

You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).


Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.


Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
*/

int swimInWater(vector<vector<int>> &grid){
    // Time complexity: O(N^2 log N)
    int n = grid.size();

    if (n == 1)
        return grid[0][0];

    int ans = max(grid[0][0], grid[n - 1][n - 1]);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // {ans, start}
    pq.push({ans, 0, 0});

    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;

    while (!pq.empty()){
        vector<int> top = pq.top();
        pq.pop();
        int val = top[0];
        int row = top[1];
        int col = top[2];
        ans = max(ans, val);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++){
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && visited[newRow][newCol] == 0){
                if (newRow == n - 1 && newCol == n - 1){
                    return ans;
                }
                pq.push({grid[newRow][newCol], newRow, newCol});
                visited[newRow][newCol] = 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>>grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<swimInWater(grid)<<endl;
}