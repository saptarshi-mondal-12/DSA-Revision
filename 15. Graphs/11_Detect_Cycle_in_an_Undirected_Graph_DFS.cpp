#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Detect Cycle in an Undirected Graph --> DFS 

Given an undirected graph with n vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Input: n = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
  (1)━━━(2) 
   ┃   / ┃ 
   ┃  /  ┃  
   ┃ /   ┃ 
  (0)   (3) 
      
Output: true
Explanation: 1 -> 2 -> 0 -> 1 is a cycle.


Input: n = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: No cycle in the graph.
*/


bool dfs(int src, int parent, vector<int>&visited, vector<vector<int>>adj){
    visited[src]=1;

    // visit adjacent nodes
    for(auto adjacentNode: adj[src]) {
        // unvisited adjacent node
        if(!visited[adjacentNode]) {
            // passing {node, parent, visited, adj}
            if(dfs(adjacentNode, src, visited, adj) == true) 
                return true; 
        }
        // visited node but not a parent node
        else if(adjacentNode != parent) return true; 
    }
    return false; 
}

bool isCycle(int n, vector<vector<int>>& edges) {
    // Time Complexity: O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

    // Space Complexity: O(N) + O(N) ~ O(N), Space for recursive stack space and visited array.


    // Creating adjacency list 
    vector<vector<int>>adj(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        // no parent node for starting point thats why -1
        if(!visited[i]){
            if(dfs(i,-1,visited,adj) == true){
                return true;
            }
        }
    }
    return false;
}



int main(){
    int n=4;
    vector<vector<int>>edges = {
        {0,1},
        {0,2},
        {1,2},
        {2,3}
    };
    cout<<isCycle(n,edges)<<endl;
}