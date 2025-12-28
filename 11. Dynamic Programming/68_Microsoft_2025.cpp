#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Microsoft 2025 
Given a 2d matrix matrix, find if you can reach from 0,0 to m-1,n-1 cell in given time T or not. The grid has some cells blocked, can only move in 4 directions, top/bottom/left/right. 

NOTE: Similar question - Shortest distance in a binary maze - Graph Q30. 


Explanation: 
-----------

To determine if the destination is reachable within a time limit, we can use a Breadth-First Search (BFS) algorithm to find the shortest time (number of moves) to reach the destination. The number of moves required is the shortest path in the grid graph where each move has a cost of 1. 

The Breadth-First Search (BFS) algorithm is used to find the shortest path in an unweighted graph. In this problem, the 2D matrix can be treated as a graph where each cell is a node and the four directions of movement are edges. 
    1. Initialization: We start at the cell (0, 0). We use a queue to manage the cells to visit and a 2D array to keep track of the minimum time (distance) taken to reach each cell. All distances are initialized to a large value or -1 (to indicate unvisited).

    2. Traversal: While the queue is not empty, we dequeue a cell, explore its valid unvisited neighbors (up, down, left, right that are within bounds and not blocked), mark them as visited, update their distance, and enqueue them.

    3. Time Check: If the destination cell (m-1, n-1) is reached, we check if its distance is less than or equal to the given time T


Q. why not dfs? 
Ans: Using DFS is possible, but it is not appropriate for this problem if your goal is to decide reachability within a time limit T efficiently and correctly.

1. Core Reason: DFS Does Not Guarantee Shortest Time
    Each move costs 1 unit of time
    You must reach (m-1, n-1) in ≤ T time
    Therefore, you need the shortest path length

    BFS property
        BFS explores nodes level by level
        The first time you reach a cell, you reach it in the minimum possible time

    DFS property
        DFS goes deep first
        It may reach the destination via a longer path, even when a shorter one exists

    ➡️ DFS cannot guarantee minimal time unless you explore all paths.


2. DFS Time Complexity Is Exponential
Without careful pruning:
    DFS time complexity ≈ O(4^(m×n))
Even with pruning:
    DFS still explores many unnecessary paths
    Risk of TLE or stack overflow for large grids


Q. Why Multiple Paths Do Not Break BFS
Ans: You are correct that: A cell (e.g., grid[7][7]) can be reached by multiple paths with different lengths. However, BFS guarantees that: The first time a cell is visited, it is reached via the shortest possible path.

--------VVVV IMP : Intuition That Usually Clicks

Think of BFS as a wave expanding outward:
The wave reaches each cell as early as physically possible
Any later wave is slower and cannot overwrite earlier arrival

Even though multiple paths may reach the same cell, BFS guarantees that the first time a cell is visited is via the shortest path.
Therefore, storing the distance once in the distance matrix is both safe and optimal.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool canReach(const vector<vector<int>>& matrix, int T) {
    // Time Complexity: O(m × n)
    // Space Complexity: O(m × n)


    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;

    // Check if start or end is blocked
    if (matrix[0][0] == 1 || matrix[m - 1][n - 1] == 1) {
        return false;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> dist(m, vector<int>(n, -1));
    dist[0][0] = 0;

    int dx[] = {-1, 1, 0, 0}; // Up, Down,
    int dy[] = {0, 0, -1, 1}; // Left, Right

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        // If destination reached, check time constraint
        if (x == m - 1 && y == n - 1) {
            return dist[x][y] <= T;
        }
        
        // Optimization: If current distance exceeds T, no need to explore further
        if (dist[x][y] >= T) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Destination not reachable
    return false;
}

// Example usage:
int main() {
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    int T = 4;
    if (canReach(matrix, T)) {
        cout << "Reachable within time T" << endl;
    } else {
        cout << "Not reachable within time T" << endl;
    }
    return 0;
}
