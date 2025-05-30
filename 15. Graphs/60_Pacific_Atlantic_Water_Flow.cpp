#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Pacific Atlantic Water Flow ---> Amazon, Google, Facebook

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.



-------------------------------------------------------------------------------------------

🔴 Step 1: Brute Force Intuition (Naive Approach)
Explain like this:

Initially, I thought of starting from every cell and simulating the flow of water to both oceans. For each cell, I would perform a DFS or BFS to see if it can reach both Pacific and Atlantic oceans.
This would involve checking if we can "travel" from this cell to both left/top and right/bottom edges following the water flow rule (can only go to equal or lower heights).

Time Complexity:

For each cell: we do a DFS that may visit almost all m*n cells

Total time: O((m * n)²) → very inefficient for large grids.

Why it's bad:

Redundant work: checking same paths repeatedly for each cell.

Doesn't scale well with bigger inputs.

✅ Step 2: Optimized Approach (Reverse Thinking)
Say this:

Then I realized a more efficient approach by reversing the problem. Instead of checking for each cell whether it can reach the oceans, I did the opposite: I started from the ocean edges and checked which cells can reach them.

Specifically:

From Pacific (left and top borders), I performed DFS to mark all cells that can flow into the Pacific.

From Atlantic (right and bottom borders), I did DFS again to mark all cells that can flow into the Atlantic.

Finally, I found the intersection of both visited matrices – those are the cells that can flow to both oceans.

✅ Time and Space Complexity
Time Complexity:
We start DFS from all border cells of both oceans.

Each DFS only visits each cell once (because we track visited).

So total time is: O(m * n).

Space Complexity:
Two visited matrices: O(m * n)

Recursion stack in worst case: O(m * n)


*/

void dfs(int i, int j, vector<vector<bool>> &ocean, vector<vector<int>> &heights){
    ocean[i][j] = true;

    int rows = heights.size();
    int cols = heights[0].size();

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // Traversing all 4 dirsction
    for (int ind = 0; ind < 4; ind++){
        int newRow = i + dr[ind];
        int newCol = j + dc[ind];

        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && heights[newRow][newCol] >= heights[i][j] && !ocean[newRow][newCol]){
            dfs(newRow, newCol, ocean, heights);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
    // Time complexity: O(m * n)
    // Space complexity: O(m * n)

    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<int>> result;

    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

    // Traversing left of pacefic ocean
    for (int i = 0; i < rows; i++){
        dfs(i, 0, pacific, heights);
    }
    // Traversing top of pacefic ocean
    for (int i = 0; i < cols; i++){
        dfs(0, i, pacific, heights);
    }

    // Traversing right of atlantic ocean
    for (int i = 0; i < rows; i++){
        dfs(i, cols - 1, atlantic, heights);
    }
    // Traversing bottom of atlantic ocean
    for (int i = 0; i < cols; i++){
        dfs(rows - 1, i, atlantic, heights);
    }

    // Finding common intersection point
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (pacific[i][j] && atlantic[i][j]){
                result.push_back({i, j});
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> result = pacificAtlantic(heights);

    for (auto& cell : result) {
        cout << "[" << cell[0] << "," << cell[1] << "] ";
    }
    cout << endl;
}