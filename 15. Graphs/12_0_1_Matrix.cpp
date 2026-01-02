#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. 01 Matrix - AMAZON 2025

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
[0,0,0]
[0,1,0]
[0,0,0]

Output: [[0,0,0],[0,1,0],[0,0,0]]


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
[0,0,0]
[0,1,0]
[1,1,1]

Output: [[0,0,0],[0,1,0],[1,2,1]]



Intuition:------------------------------------------------------

Breadth First Search, BFS, is a traversal technique where we visit the nodes level-wise, i.e., it visits the same level nodes simultaneously, and then moves to the next level.

The intuition is that BFS will take a step from cells containing 0 and will reach out to all ones that are at a distance of one. Apparently, we can say that the nearest 0 to the 1s is at a distance of one. Again if we take another step, we will reach the next set of ones, for these one 0 is at a distance of two. If we continue the same, till we can go, we can reach all the 1’s possible. 

We will choose the BFS algorithm as it moves step by step and we want all of them to traverse in a single step together so that we can have a minimum count with us.

Approach:

Initial configuration:
    1. Queue: Define a queue and insert the pair of starting nodes’ coordinates along with the steps (<coordinates, step>). For example, ((2, 1), 2) means cell (2, 1) is the source node and the nearest 1 can be found at a distance of 2 from the node.

    2. Visited array: an array initialized to 0 indicating unvisited nodes.

    3. Distance matrix: stores the distance of the nearest cell having 1 for every particular cell.

The algorithm steps are as follows:

    1. Push the pair of starting points and its steps (<coordinates, stept>) in the queue, and mark the cell as visited.

    2. Start the BFS traversal, pop out an element from the queue every time, and travel to all its unvisited neighbors having 0. 
    
    3. For every neighboring unvisited 0, we can mark the distance to be +1 of the current node distance and store it in the distance 2D array, and at the same time insert <{row, col}, steps+1> into the queue.

    4. Repeat the steps until the queue becomes empty and then return the distance matrix where we have stored the steps.
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    // Time compleixty: O(NxM + NxMx4) ~ O(N x M) For the worst case, the BFS function will be called for (N x M) nodes, and for every node, we are traversing for 4 neighbors, so it will take O(N x M x 4) time.

    // Space complexity: O(NxM) + O(NxM) + O(NxM)

    int n=mat.size();
    int m=mat[0].size();

    // visited and distance matrix
    vector<vector<int>>visited(n, vector<int>(m,0));
    vector<vector<int>>dist(n, vector<int>(m,0));

    // <coordinates, steps>
    queue<pair<pair<int,int>, int>> q; 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // start BFS if cell contains 0
            if(mat[i][j] == 0){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
            else {
                visited[i][j] = 0; 
            }
        }
    }

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int step=q.front().second;
        q.pop();

        dist[row][col]=step;

        // for all 4 neighbours (up, right, down, left)
        int r=row-1, c=col;
        if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==0){
            q.push({{r,c},step+1});
            visited[r][c]=1;
        }
        r=row, c=col+1;
        if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==0){
            q.push({{r,c},step+1});
            visited[r][c]=1;
        }
        r=row+1, c=col;
        if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==0){
            q.push({{r,c},step+1});
            visited[r][c]=1;
        }
        r=row, c=col-1;
        if(r>=0 && r<n && c>=0 && c<m && visited[r][c]==0){
            q.push({{r,c},step+1});
            visited[r][c]=1;
        }
    }
    // return distance matrix
    return dist;
}

int main(){
    
    vector<vector<int>>mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
    vector<vector<int>> ans = updateMatrix(mat);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
}