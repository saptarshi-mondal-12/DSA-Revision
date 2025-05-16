#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Shortest Path in Undirected Graph - BFS

Given an Undirected Graph having unit weight, find the shortest path from the source to all other nodes in this graph. In this problem statement, we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.


Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation: Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2


Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4


NOTE - All methods gives same answer - 
    Method 1: Simple BFS using queue Q27. 
    Method 2: Dijkstra Algorithm using priority Queue - min-heap data structure Q28.
    Method 3: Dijkstra Algorithm using set data structure
*/


vector<int>shortestPath(int n, vector<vector<int>>edges, int src){
    // Time complexity: O(E) { for creating the adjacency list from given list ‘edges’} + O(N + 2E) { for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array} ~ O(N+2E). 

    // Space complexity: O(N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) {for the dist array storing updated shortest paths} + O( N+2E) {for the adjacency list} ~ O(N+E) .

    // 1. Creating adjacency list
    vector<vector<pair<int,int>>> adjacencyList(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];

        adjacencyList[u].push_back({weight, v});
        adjacencyList[v].push_back({weight, u});
    }

    // A distance array of size n initialised with a large number to indicate that initially all the nodes are untraversed.    
    vector<int>distance(n,1e9);
    
    // BFS Implementation.
    distance[src] = 0; 

    queue<pair<int,int>> q;
    // storing order {node,weight}
    q.push({0,src}); 

    while(!q.empty()) {
        int dis = q.front().first;
        int node = q.front().second;
        q.pop(); 

        for (auto it : adjacencyList[node]){
            int wt = it.first;
            int v = it.second;
            if (dis + wt < distance[v]){
                distance[v] = dis + wt;
    
                // If current distance is smaller, push it into the queue.
                q.push({dis + wt, v});
            }
        }
    }
    
    // Updated shortest distances are stored in the resultant array ‘ans’.
    // Unreachable nodes are marked as -1. 
    for(int i = 0;i<n;i++) {
        if(distance[i] == 1e9) {
            distance[i] = -1; 
        }
    }
    return distance; 
}

int main(){
    int n=5;
    vector<vector<int>> edges= {{0, 1, 4}, {0, 2, 8}, {1, 4, 6}, {2, 3, 2}, {3, 4, 10}};
    int src=0;

    vector<int>ans=shortestPath(n,edges,src);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
