#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Shortest distance in a binary maze

Given a nxm matrix grid where each element can either be 0 or 1.
You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 
if path is not possible between source cell and destination cell then return -1

grid[][]={
        {1,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,0,0},
        {1,0,0,1}}
source = {0,1}
destination = {2,2}
output = 3
*/

int shortestPath(vector<vector<int>>&grid, pair<int,int>&source, pair<int,int>&destination){
    // Time complexity: O( 4*N*M ) { N*M are the total cells, for each of which we also check 4 adjacent nodes for the shortest path length}
    
    // space complexity: O( N*M ), Where N = No. of rows of the binary maze and M = No. of columns of the binary maze.

    int n=grid.size();
    int m=grid[0].size();

    // If start or end is blocked, no path
    if (grid[0][0] == 0 || grid[n-1][n-1] == 0) 
        return -1;

    // Special case: single cell
    if (n == 1) 
        return 1;

    
    // source
    int a=source.first;   // row
    int b=source.second; // col

    // destination
    int c=destination.first;   // row
    int d=destination.second; // col


    // if we source and destination are equal 
    if(a==c && b==d) return 0;

    vector<vector<int>>distance(n, vector<int>(m, 1e9));
    distance[a][b]=0;

    queue<pair<int,pair<int,int>>>q;
    q.push({0,{a,b}});

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};

    while(!q.empty()){
        int dis=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;

        q.pop();

        // travel to all adjacent node - in 4 direction (up, right, down, left) 
        for(int i=0;i<4;i++){
            int newRow=row+dr[i];
            int newCol=col+dc[i];

            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1 && dis+1 < distance[newRow][newCol]){
                distance[newRow][newCol]=dis+1;

            

                // if i am at my destination then this will be my answer 
                if(newRow==c && newCol==d){
                    return distance[newRow][newCol];
                }

                q.push({dis+1,{newRow,newCol}});
            }
        }
    }
    // never reach the destination
    return -1; 
}

int main(){
    vector<vector<int>>grid = {
        {1,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,0,0},
        {1,0,0,1}};
    pair<int,int>source={0,1};
    pair<int,int>destination={0,2};

    cout<<shortestPath(grid, source, destination);
}