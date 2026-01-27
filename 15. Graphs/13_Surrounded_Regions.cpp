#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Surrounded Regions - AMAZON 2025 2 Times

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Input: board = [
            ["X","X","X","X"],
            ["X","O","O","X"],
            ["X","X","O","X"],
            ["X","O","X","X"]]
Output: [
            ["X","X","X","X"],
            ["X","X","X","X"],
            ["X","X","X","X"],
            ["X","O","X","X"]
        ]
Explanation: In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.


Input: board = [["X"]]
Output: [["X"]]


Intuition: ------------------------------------------------------

Anyone who is connected to boundery cannot be converted to X.


The boundary elements in the matrix cannot be replaced with ‘X’ as they are not surrounded by ‘X’ from all 4 directions. This means if ‘O’ (or a set of ‘O’) is connected to a boundary ‘O’ then it can’t be replaced with ‘X’. 

The intuition is that we start from boundary elements having ‘O’ and go through its neighboring Os in 4 directions and mark them as visited to avoid replacing them with ‘X’. 



Approach : 
DFS is a traversal technique that involves the idea of recursion.. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes.

The algorithm steps are as follows:
    1. Create a corresponding visited matrix and initialize it to 0.
    2. Start with boundary elements, once ‘O’ is found, call the DFS function for that element and mark it as visited. In order to traverse for boundary elements, you can traverse through the first row, last row, first column, and last column. 
    3. DFS function call will run through all the unvisited neighboring ‘O’s in all 4 directions and mark them as visited so that they are not converted to ‘X’ in the future. The DFS function will not be called for the already visited elements to save time, as they have already been traversed. 
    4. When all the boundaries are traversed and corresponding sets of ‘O’s are marked as visited, they cannot be replaced with ‘X’. All the other remaining unvisited ‘O’s are replaced with ‘X’. This can be done in the same input matrix as the problem talks about replacing the values, otherwise tampering with data is not advised. 
*/

void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &board){
    visited[row][col] = 1;

    int n = board.size();
    int m = board[0].size();

    // Traversing all 4 directions (top, right, down, left)
    int r = row - 1, c = col;
    if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !visited[r][c]){
        dfs(r, c, visited, board);
    }

    r = row, c = col + 1;
    if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !visited[r][c]){
        dfs(r, c, visited, board);
    }
    
    r = row + 1, c = col;
    if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !visited[r][c]){
        dfs(r, c, visited, board);
    }

    r = row, c = col - 1;
    if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 'O' && !visited[r][c]){
        dfs(r, c, visited, board);
    }
}
vector<vector<char>> fill(vector<vector<char>> &board){
    // Time complexity: O(m) + O(n) + O(nxm*4)
    // Space complexity: O(nxm) + O(nxm)


    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Traversing first and last row
    for (int j = 0; j < m; j++){
        // First row
        if (board[0][j] == 'O'){
            dfs(0, j, visited, board);
        }

        // Last row
        if (board[n - 1][j] == 'O'){
            dfs(n - 1, j, visited, board);
        }
    }

    // Traversing first and last columb
    for (int i = 0; i < n; i++){
        // First row
        if (board[i][0] == 'O'){
            dfs(i, 0, visited, board);
        }

        // Last row
        if (board[i][m - 1] == 'O'){
            dfs(i, m - 1, visited, board);
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (!visited[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
    }
    return board;
}

int main(){
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    vector<vector<char>> ans = fill(board);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
}