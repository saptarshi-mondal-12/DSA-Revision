#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Longest Path in a Directed Acyclic Graph

Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph. Return the distance array,  in the distance array instead of passing INF you need to have INT_MIN driver will automatically update it to INF.


Input: n = 3, m = 2, s = 0, edges[] = [[0,2,1],[0,1,1]]
Output: distance[] = [0,1,1]
Explanation: The shortest distance of vertex 1 from 0 is 1 and that of two is also 1.


Input: n = 6,m = 10, s = 1, edges[] = [[0,1,5],[0,2,3],[1,3,6],[1,2,2],[2,4,4],[2,5,2],[2,3,7],[3,5,1],[3,4,-1],[4,5,-2]]
Output: distance[] = [INF,0,2,9,8,10]
Explanation: The vertex zero is not reachable from vertex 1 so its distance is INF, for 2 it is 2, for 3 it is 9, the same goes for 4 and 5.


Expected Time Complexity: O(V+E)
Expected Auxiliary Space: O(V)


Intuition:

We use dijkstra algorithm -> Instead of finding the shortest path we find longest path. We can do a slightly modification in dijkstra algo.
*/

vector<int> maximumDistance(vector<vector<int>> edges, int n, int src){
    // NOTE: We can also use the solution Q.26

    // 1. Creating adjacency list
    vector<vector<pair<int, int>>> adjacencyList(n);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        adjacencyList[u].push_back({weight, v});
    }

    // Implementing Dijkstra Algorithm using priority Queue

    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialising distTo list with a large number to indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distance(n, INT_MIN);

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

            // finding longest
            if (dis + wt > distance[v]){
                distance[v] = dis + wt;

                // If current distance is smaller, push it into the queue.
                pq.push({dis + wt, v});
            }
        }
    }
    // Return the list containing shortest distances from source to all the nodes.
    return distance;
}

int main() {
    int n = 6, m = 10, src = 1;
    vector<vector<int>> edges = {
        {0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2},
        {2, 4, 4}, {2, 5, 2}, {2, 3, 7}, {3, 5, 1},
        {3, 4, -1}, {4, 5, -2}
    };

    vector<int>distance=maximumDistance(edges, n, src);
    for(auto it: distance){
        cout<<it<<" ";
    }
}