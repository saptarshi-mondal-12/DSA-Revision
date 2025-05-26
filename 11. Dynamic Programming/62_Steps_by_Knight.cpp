#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Steps by Knight

Given a square chessboard of size (n x n), the initial position and target postion of Knight are given. Find out the minimum steps a Knight will take to reach the target position.

Note: The initial and the target position coordinates of Knight have been given according to 1-base indexing.

Input: n = 3, knightPos[] = [3, 3], targetPos[]= [1, 2]
Output: 1
Explanation: Knight takes 1 step to reach from (3, 3) to (1 ,2).


Input: n = 6, knightPos[] = [4, 5],targetPos[] = [1, 1]
Output: 3
Explanation:Knight takes 3 step to reach from (4, 5) to (1, 1): (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
*/


// Recursion - Time limit exceed----------------------------------------------------------------
int minSteps_1(int i, int j, vector<int> &targetPos, int n){
    // Out of bounds check
    if (i < 0 || j < 0 || i >= n || j >= n)
        return INT_MAX;

    // Base case: reached target
    if (i == targetPos[0] && j == targetPos[1]){
        return 0; // No more steps needed
    }

    int mini = INT_MAX;

    // Knight's 8 possible moves
    int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (int ind = 0; ind < 8; ind++){
        int newRow = i + dir[ind][0];
        int newCol = j + dir[ind][1];

        int jumps = minSteps_1(newRow, newCol, targetPos, n);
        if (jumps != INT_MAX){
            mini = min(mini, 1 + jumps);
        }
    }

    return mini;
}

int minStepToReachTarget_1(vector<int> &knightPos, vector<int> &targetPos, int n){
    // Time complexity:
    // Space complexity:

    // Convert to zero-based indexing
    int i = knightPos[0] - 1;
    int j = knightPos[1] - 1;

    targetPos[0] -= 1;
    targetPos[1] -= 1;

    int ans = minSteps_1(i, j, targetPos, n);

    return ans;
}





// Memoization - Time limit exceed ------------------------------------------------------------
int minSteps_2(int i, int j, vector<int> &targetPos, int n, vector<vector<int>>& dp){
    // Out of bounds check
    if (i < 0 || j < 0 || i >= n || j >= n)
        return INT_MAX;

    // Base case: reached target
    if (i == targetPos[0] && j == targetPos[1]){
        return 0; // No more steps needed
    }

    // Already computed
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    // Knight's 8 possible moves
    int dir[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (int ind = 0; ind < 8; ind++){
        int newRow = i + dir[ind][0];
        int newCol = j + dir[ind][1];

        int jumps = minSteps_2(newRow, newCol, targetPos, n, dp);
        if (jumps != INT_MAX){
            mini = min(mini, 1 + jumps);
        }
    }

    dp[i][j] = mini;
    return dp[i][j];
}

int minStepToReachTarget_2(vector<int> &knightPos, vector<int> &targetPos, int n){
    // Time complexity:
    // Space complexity:

    // Convert to zero-based indexing
    int i = knightPos[0] - 1;
    int j = knightPos[1] - 1;

    targetPos[0] -= 1;
    targetPos[1] -= 1;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = minSteps_2(i, j, targetPos, n, dp);

    return ans;
}




// Tabulation -------------------------------------------------------------------------------
int minStepToReachTarget_3(vector<int> &knightPos, vector<int> &targetPos, int n){
    // Time complexity: O(n^2)
    // Space complexity: O(N²) + O(N²) + O(N²) = O(N²)


    // Convert to zero-based indexing
    int startX = knightPos[0] - 1;
    int startY = knightPos[1] - 1;
    int targetX = targetPos[0] - 1;
    int targetY = targetPos[1] - 1;

    // If already at target
    if (startX == targetX && startY == targetY) return 0;



    // Initialize visited and steps grid
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> steps(n, vector<int>(n, 0));

    // BFS queue: stores {x, y}
    queue<pair<int, int>> q;
    q.push({startX, startY});

    visited[startX][startY] = true;

    // Direction vectors for knight's moves
    vector<pair<int, int>> directions = {{2, 1},{2, -1},{-2, 1},{-2, -1},{1, 2},{1, -2},{-1, 2},{-1, -2}};

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int ind=0; ind < 8; ind++) {
            int newX = row + directions[ind].first;
            int newY = col + directions[ind].second;

            // Valid move
            if (newX >= 0 && newY >= 0 && newX < n && newY < n && !visited[newX][newY]) {
                visited[newX][newY] = true;
                steps[newX][newY] = steps[row][col] + 1;

                if (newX == targetX && newY == targetY)
                    return steps[newX][newY];

                q.push({newX, newY});
            }
        }
    }

    return -1; // Not reachable
}



int main(){
    int n = 3;
    vector<int> knightPos = {3, 3};
    vector<int> targetPos = {1, 2};

    cout << minStepToReachTarget_3(knightPos, targetPos, n) << endl;
}