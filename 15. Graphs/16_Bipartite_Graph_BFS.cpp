#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Bipartite Graph ------> Using BFS

Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, it is called a bipartite graph.

REMEMBER: 
    1. Linear graphs with no cycle are always bipartite.
    2. Any graph with even cycle length can also be bipartite.
    3. Any graph with odd cycle length can never be a bipartite. 


Example 1:
Output: true
           (R)━━━━━(Y)
           /         \
          /           \
(R)━━━━━(Y)           (R)━━━━━(Y)
          \           /
           \         /
           (R)━━━━━(Y)



Example 2:
Output: False
            (R)
            / \
           /   \
          /     \
(R)━━━━━(Y)     (Y)━━━━━(R)
        ┃        ┃
        ┃        ┃
        (R)━━━━━(Y)

Input: n = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]
Output: False
            (R)     (R)
            / \     /
           /   \   /
          /     \ /
        (Y)━━━━━(Y)



Output: false 
Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs.


Intuition:---------------------------------------------------------------

A bipartite graph is a graph which can be coloured using 2 colours such that no adjacent nodes have the same colour. Any linear graph with no cycle is always a bipartite graph. With a cycle, any graph with an even cycle length can also be a bipartite graph. So, any graph with an odd cycle length can never be a bipartite graph.

The intuition is the brute force of filling colours using any traversal technique, just make sure no two adjacent nodes have the same colour. If at any moment of traversal, we find the adjacent nodes to have the same colour, it means that there is an odd cycle, or it cannot be a bipartite graph.

Example Where Bipartite Fails

V = 3, edges = [[0,1], [1,2], [2,0]], m = 3
This graph is a triangle (3-cycle), which is not bipartite.But it can be 3-colored easily. So, the graph is not bipartite, but the answer to the M-coloring problem with m=3 is true.

*/

bool check(int start, vector<vector<int>> adjacencyList, vector<int> &color){
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (auto it : adjacencyList[node]){
            // if the adjacent node is yet not colored
            // we will color it opposite color of the node
            if (color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            // if the adjacent guy has the same color
            // someone did color it on some other path
            else if (color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int n, vector<vector<int>> &edge){
    // Time complexity: O(N) + O(2E)
    // Space compleixty: O(N) + O(N)

    // Creating adjacency list
    vector<vector<int>> adjacencyList(n);
    for (int i = 0; i < edge.size(); i++){
        int u = edge[i][0];
        int v = edge[i][1];
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    // We will take a color vector and initialize with -1 means not colored
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++){
        if (color[i] == -1){
            if (check(i, adjacencyList, color) == false){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n = 4;
    vector<vector<int>> edge = {{0, 3}, {1, 2}, {3, 2}, {0, 2}};
    cout<<isBipartite(n,edge);
}