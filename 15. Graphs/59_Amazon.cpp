#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Minimum edges to reverse to make path from a source to a destination

Given a directed graph with n nodes and m edges. A source node and a destination node are also given, we need to find how many edges we need to reverse in order to make at least 1 path from the source node to the destination node.
Note: In case there is no way then return -1.

Minimum edges to reverse to make path from a source to a destination

Input: n = 7, src = 0, dst = 6
edges[][] = [ [0, 1], [2, 1], [2, 3], [6, 3], [6, 4], [4, 5], [5, 1] ]
Output: 2
Explanation: In above graph there are two paths from node 0 to node 6:
0 -> 1 -> 2 -> 3 -> 6
0 -> 1 -> 5 -> 4 -> 6
For the first path, two edges need to be reversed, and for second path, three edges need to be reversed, thus the minimum edges to be reversed is 2.

Input: n = 4, src = 1, dst = 4
edges[][] = [ [1, 2], [2, 3], [3, 4] ]
Output: 0
Explanation: One path already exists between node 1 to 4: 1 -> 2 -> 3 -> 4. Thus no nodes need to be reversed.


Intuition-----------------------------------------------------------------------------------------

[Expected Approach] - By Creating Reverse Edges - O(m * log(n)) Time and O(n + m) Space
The idea here is to make the graph undirected by adding all edges in the reverse direction. Assign weight zero to all edges that are not reversed and weight 1 to all edges that are reversed. Then, use the Dijkstra algorithm to find the minimum weight path from the starting node to the ending node to get the minimum number of operations.

https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/

Practice Link : https://www.geeksforgeeks.org/problems/minimum-edges/1
*/

int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst){
    // 1. Creating adjacency list
    vector<vector<pair<int, int>>> adjacencyList(n + 1);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjacencyList[u].push_back({0, v});
        adjacencyList[v].push_back({1, u});
    }

    // Implementing Dijkstra Algorithm using priority Queue

    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialising distTo list with a large number to indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distance(n + 1, 1e9);

    // Source initialised with dist=0.
    distance[src] = 0;

    // storing order {node,weight}
    pq.push({0, src});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (auto it : adjacencyList[node]){
            int wt = it.first;
            int v = it.second;
            if (dis + wt < distance[v]){
                distance[v] = dis + wt;

                // If current distance is smaller, push it into the queue.
                pq.push({dis + wt, v});
            }
        }
    }
    // Return the list containing shortest distances from source to all the nodes.

    if (distance[dst] == 1e9)
        return -1;
    return distance[dst];
}

int main(){
    int n = 7, src = 0, dst = 6;
    vector<vector<int>> edges = {{0, 1}, {2, 1}, {2, 3}, {6, 3}, {6, 4}, {4, 5}, {5, 1}};
    cout<<minimumEdgeReversal(edges, n, src, dst);

}