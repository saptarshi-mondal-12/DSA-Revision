#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Rat in a Maze Problem

Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.

Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.


Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.


Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell is blocked.


Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.

*/

void findPathHelper(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &vis){

    // Base case
    if (i == n - 1 && j == n - 1){
        ans.push_back(move);
        return;
    }

    // Traversing all 4 direction 

    // downward
    if (i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1){
        vis[i][j] = 1;
        findPathHelper(i + 1, j, maze, n, ans, move + 'D', vis);
        vis[i][j] = 0;
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1){
        vis[i][j] = 1;
        findPathHelper(i, j - 1, maze, n, ans, move + 'L', vis);
        vis[i][j] = 0;
    }

    // right
    if (j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1){
        vis[i][j] = 1;
        findPathHelper(i, j + 1, maze, n, ans, move + 'R', vis);
        vis[i][j] = 0;
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1){
        vis[i][j] = 1;
        findPathHelper(i - 1, j, maze, n, ans, move + 'U', vis);
        vis[i][j] = 0;
    }
}
vector<string> ratInMaze(vector<vector<int>> &maze){
    // Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
    // Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).

    int n = maze.size();
    vector<string> ans;

    // If start or end is blocked, return empty
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
        return ans;

    vector<vector<int>> vis(n, vector<int>(n, 0));

    string move = "";

    findPathHelper(0, 0, maze, n, ans, move, vis);
    sort(ans.begin(), ans.end()); // Lexicographical order
    return ans;
}

int main(){
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = ratInMaze(maze);

    if (paths.empty()) {
        cout << "No path found.\n";
    }
    else{
        for (const string& path : paths)
            cout << path << " ";
        cout << endl;
    }
}