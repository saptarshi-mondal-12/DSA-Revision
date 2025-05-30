#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Detect a negative cycle in a Graph | (Bellman Ford)

Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.

Input: n = 3, edges = {{0,1,-1},{1,2,-2},{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight cycle as 0->1->2->0 with weight -1,-2,-3.


Input: n = 3, edges = {{0,1,-1},{1,2,-2},{2,0,3}}
Output: 0
Explanation: The graph does not contain any negative weight cycle.



Intuition: Checkout Bellman Ford Topic Q.33

*/

int isNegativeWeightCycle(int n, vector<vector<int>> edges){
    // Code here
    vector<int> distance(n, 0);

    // Run Bellman-Ford for n times to detect cycle
    for (int times = 0; times < n - 1; times++){
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if (distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }

    // Nth relaxation to check negative cycle (if it contains cycle means it still reducing)
    // if a graph has any path weight which is lesser than 0 then i can say that graph has negetive cycle/
    // One more relaxation to detect negative weight cycle

    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if (distance[u] + wt < distance[v]){
            return true;
        }
    }

    return false;
}

int main(){
    int n=3;
    vector<vector<int>>edges = {{0,1,-1},{1,2,-2},{2,0,-3}};
    cout<<isNegativeWeightCycle(n, edges);
}