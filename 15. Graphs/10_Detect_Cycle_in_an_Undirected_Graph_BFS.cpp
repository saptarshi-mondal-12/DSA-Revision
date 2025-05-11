#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Detect Cycle in an Undirected Graph --> BFS 

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


Intuition: ------------------------------
he intuition is that we start from a node, and start doing BFS level-wise, if somewhere down the line, we visit a single node twice, it means we came via two paths to end up at the same node. It implies there is a cycle in the graph because we know that we start from different directions but can arrive at the same node only if the graph is connected or contains a cycle, otherwise we would never come to the same node again.  

Initial configuration:
    Queue: Define a queue and insert the source node along with parent data (<source node, parent>). For example, (2, 1) means 2 is the source node and 1 is its parent node.
    
    Visited array: an array initialized to 0 indicating unvisited nodes.  
*/

bool detect(int src, vector<int>&visited, vector<vector<int>>adj){
    // Mark src as visited
    visited[src]=1;
    
    // store <source node, parent node>
    queue<pair<int,int>>q;
    q.push({src,-1});
    
    while(!q.empty()){
        int node = q.front().first; 
        int parent = q.front().second; 
        q.pop(); 
          
        // go to all adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // if adjacent node is unvisited
            if(!visited[adjacentNode]) {
                visited[adjacentNode] = 1; 
                q.push({adjacentNode, node}); 
            }
            // if adjacent node is visited and is not it's own parent node
            else if(parent != adjacentNode) {
                // yes it is a cycle
                return true; 
            }
        }
    }
    // there's no cycle
    return false; 
    
}
bool isCycle(int n, vector<vector<int>>& edges) {
    // Time Complexity: O(N) + O(N + 2E) + O(N), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes. In the case of connected components of a graph, it will take another O(N) time.

    // Space Complexity: O(N) + O(N) + O(N) ~ O(N), Space for adjacency list and queue data structure and visited array.



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
        if(!visited[i]){
            if(detect(i,visited,adj) == true){
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