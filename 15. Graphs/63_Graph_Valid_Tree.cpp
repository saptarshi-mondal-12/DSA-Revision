#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Graph Valid Tree | Check if a given graph is tree or not

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.


Input: n = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
Output: true

Input:n = 5
edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
Output: false


---------------------------------------------------------------------------------------

According to the definition of a tree, a tree is an undirected graph with no cycles, all the nodes are connected as one component,

An undirected graph is a tree if it has the following properties. 
    1. There is no cycle. 
    2. The graph is connected means single component.


Q. How to detect cycles in an undirected graph? 
Ans: We can either use BFS or DFS. For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not the parent of v, then there is a cycle in the graph. If we don’t find such an adjacent for any vertex, we say that there is no cycle.

We can use the Depth First Search (DFS) algorithm to detect a cycle in the graph. Since a tree has only one component, we can start the DFS from any node, say node 0. During the traversal, we recursively visit its neighbors (children). If we encounter any already visited node that is not the parent of the current node, we return false as it indicates a cycle.



Q. How to check for connectivity 
(single component) ? 
Ans: Since the graph is undirected, we can start BFS or DFS from any vertex and check if all vertices are reachable or not. If all vertices are reachable, then the graph is connected, otherwise not.


NOTE: if we observe carefully the definition of tree and its structure we will deduce that if a graph is connected and has n - 1 edges exactly then the graph is a tree.

*/

bool dfs(int src, int parent, vector<int> &visited, vector<vector<int>> adj){
    visited[src] = 1;

    // visit adjacent nodes
    for (auto adjacentNode : adj[src]){
        // unvisited adjacent node
        if (!visited[adjacentNode]){
            // passing {node, parent, visited, adj}
            if (dfs(adjacentNode, src, visited, adj) == true)
                return true;
        }
        // visited node but not a parent node
        else if (adjacentNode != parent)
            return true;
    }
    return false;
}

bool validTree(int n, vector<vector<int>> &edges){
    // Time Complexity: O(V + E) 
    // Spac complexity: O(V)


    // Creating adjacency list
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m=edges.size();
    if (m != n - 1) return false; // optimization: tree must have n - 1 edges

    vector<int> visited(n, 0);

    // 1. checks for cycle -> If it return true means cycle exists => not a tree
    if (dfs(0, -1, visited, adj) == true)
        return false;

    // Check if the graph is fully connected - single component
    for (int i = 0; i < n; ++i){
        if (visited[i] == 0)
            return false;
    }

    return true;
}

int main(){
    int n=5;
    vector<vector<int>> edges={{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout<<validTree(n,edges)<<endl;
}