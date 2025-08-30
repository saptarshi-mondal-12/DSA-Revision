#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Number of Islands

Problem Statement: Given a grid of size NxM (N is the number of rows and M is the number of columns in the grid) consisting of '0's (Water) and ‘1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Input: 
grid = {{'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'}}

Output: 3
Explanation: There are 3 islands as the different components are surrounded by water (i.e. 0), and there is no land connectivity in either of the 8 directions hence separating them into 3 islands.

Intuition: 
We runs a loop for each and every coordinates(i,j) and check if it is a land i.e 1. 
if it is a land we do a bfs/dfs traversal.
*/


void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid){
    // mark it visited 
    visited[row][col]=1;

    queue<pair<int,int>>q;
    q.push({row,col});

    int n = grid.size(); 
    int m = grid[0].size(); 

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();


        // traverse in the neighbours and mark them if its a land -> total 8 directions 

        // top----------------------------------
        int r=row-1, c=col-1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }
        r=row-1, c=col;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }
        r=row-1, c=col+1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }

        // middle----------------------------------
        r=row, c=col-1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }
        r=row, c=col;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }
        r=row, c=col+1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }

        // below----------------------------------
        r=row+1, c=col-1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }
        r=row+1, c=col;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }
        r=row+1, c=col+1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == '1' && !visited[r][c]){
            visited[r][c]=1;
            q.push({r,c});
        }
        
    }
}
int numIslands(vector<vector<char>>&grid){
    // Time Complexity: O(NxM + NxMx9), N² for the nested loops, and NxMx9 for the overall DFS of the matrix, that will happen throughout if all the cells are filled with 1.

    // Space Complexity: O(NxM) for visited array max queue space O(N²), If all are marked as 1 then the maximum queue space will be N².

    int n=grid.size();
    int m=grid[0].size();

    // create visited array and initialise to 0
    vector<vector<int>>visited(n, vector<int>(m,0));

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                count++;
                bfs(i,j,visited,grid);
            }
        }
    }
    return count;
}

int main(){
    vector<vector<char>>grid={
        {'0', '1', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '0', '1', '0'},
        {'0', '0', '0', '0'},
        {'1', '1', '0', '1'}
    };

    cout<<numIslands(grid)<<endl;
}
