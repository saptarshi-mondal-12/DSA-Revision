#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Rotting Oranges

You are given an m x n grid where each cell can have one of three values:
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.



Intution:-------------------------------------

The idea is that for each rotten orange, we will find how many fresh oranges there are in its 4 directions. If we find any fresh orange we will make it into a rotten orange. One rotten orange can rotten up to 4 fresh oranges present in its 4 directions. For this problem,  we will be using the BFS ( Breadth-First Search ) technique.
*/

int orangesRotting(vector<vector<int>>& grid) {
    // Time complexity: O(NxM) + O(NxMx4) + O(NxM) = O(N x M)
    // space complexity: O(NxM) + O(NxM) = O(N x M)

    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited = grid;

    // {{r,c},time}
    queue<pair<pair<int, int>, int>>q;

    // getting all the rotten oranges 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }
        }
    }

    // BFS Traversal because we want to do level wise traversal
    int time=0;
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        q.pop();
        time=max(time, t);

        // Rot all 4 neighboring oranges if the neighbor is a fresh orange (i.e. 1)
        int r=row-1, c=col;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && visited[r][c]!=2){
            visited[r][c]=2;
            q.push({{r,c},t+1});
        }
        r=row, c=col+1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && visited[r][c]!=2){
            visited[r][c]=2;
            q.push({{r,c},t+1});
        }
        r=row+1, c=col;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && visited[r][c]!=2){
            visited[r][c]=2;
            q.push({{r,c},t+1});
        }
        r=row, c=col-1;
        if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1 && visited[r][c]!=2){
            visited[r][c]=2;
            q.push({{r,c},t+1});
        }
    }

    // check if there is any fresh orange left 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==1){
                return -1;
            }
        }
    }
    return time;
}

int main(){
    vector<vector<int>>grid{
	    {2,1,1},
	    {1,1,0},
	    {0,1,1}
	};
    cout<<orangesRotting(grid)<<endl;
}