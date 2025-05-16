#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Print Shortest Path - Dijkstra’s Algorithm

You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n, and if the path does not exist then return a list consisting of only -1.


Input: n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output: 1 4 3 5
Explanation: The source vertex is 1. Hence, the shortest distance path of node 5 from the source will be 1->4->3->5 as this is the path with a minimum sum of edge weights from source to destination.

Input: V = 4, E = 4
edges = [[1,2,2], [2,3,4], [1,4,1],[4,3,3]]
Output: 1 4 
Explanation: The source vertex is 1. Hence, the shortest distance path of node 4 from the source will be 1->4 as this is the path with the minimum sum of edge weights from source to destination.

Intuition:

The intuition behind the above problem is based on Dijkstra's Algorithm with a combination of a little bit of memoization in order to print the shortest possible path and not just calculate the shortest distance between the source and the destination node. In order to print the path we will try to remember the node from which we came while traversing each node by Dijkstra’s Algorithm along with calculating the shortest distance. 

An array called ‘parent’ can be used for this purpose which would store the parent node for each node and will update itself if a shorter path from a node is found at some point in time. This will help us to print the path easily at the end by backtracking through the parent array till we reach the source node.

*/

vector<int> shortestPath(int n, vector<vector<int>> &edges, int source){
    // Time complexity : O( E log(V) ) for Dijkstra’s Algorithm  + O(V) for backtracking in order to find the parent for each node Where E = Number of edges and V = Number of Nodes.

    // Space Complexity: O( |E| + |V| ) { for priority queue and dist array } + O( |V| ) { for storing the final path }


    // NOTE: 1 based indexing 1 to n (inclusive)


    // 1. Creating adjacency list
    vector<vector<pair<int, int>>> adjacencyList(n + 1);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adjacencyList[u].push_back({weight, v});
        adjacencyList[v].push_back({weight, u});
    }

    // Implementing Dijkstra Algorithm using priority Queue

    // Create a priority queue for storing the nodes as a pair {dist, node}
    // where dist is the distance from source to the node.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialising distTo list with a large number to indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distance(n + 1, 1e9);

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }

    // Source initialised with dist=0.
    distance[source] = 0;

    // storing order {node,weight}
    pq.push({0,1});

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
                // Update the parent of the adjNode to the recent
                // node where it came from.
                parent[v] = node;
            }
        }
    }
    // If distance to a node could not be found, return an array containing -1.
    if (distance[n] == 1e9)
        return {-1};

    // Store the final path in the ‘path’ array.
    vector<int> path;

    int node = n;

    // Iterate backwards from destination to source through the parent array.
    while (parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);

    // Since the path stored is in a reverse order, we reverse the array
    // to get the final answer and then return the array.
    reverse(path.begin(), path.end());

    return path;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    int src = 1;

    vector<int> ans = shortestPath(n, edges, src);
    for (auto it : ans){
        cout << it << " ";
    }
    cout << endl;
}