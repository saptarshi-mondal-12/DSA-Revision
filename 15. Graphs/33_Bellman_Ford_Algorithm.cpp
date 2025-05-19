#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Bellman Ford Algorithm

Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.


Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 → 1
For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3
For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4


Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
Output: [-1]
Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1, where the total weight of the cycle is negative.


----------------------------------------------------------------------------------------------------------

The bellman-Ford algorithm helps to find the shortest distance from the source node to all other nodes. But, we have already learned Dijkstra's algorithm (Dijkstra's algorithm article link) to fulfill the same purpose. Now, the question is how this algorithm is different from Dijkstra's algorithm.

While learning Dijkstra's algorithm, we came across the following two situations, where Dijkstra's algorithm failed:
    1. If the graph contains negative edges.
    2. If the graph has a negative cycle (In this case Dijkstra's algorithm fails to minimize the distance, keeps on running, and goes into an infinite loop. As a result it gives TLE error).

Negative Cycle: A cycle is called a negative cycle if the sum of all its weights becomes negative. The following illustration is an example of a negative cycle:
        -2
   (1)----->(2)
    \       /
     \     / -1
    2 \   /
       \ /
       (3)

    Sum= 2+(-2)+(-1) => -1

Bellman-Ford's algorithm successfully solves these problems. It works fine with negative edges as well as it is able to detect if the graph contains a negative cycle. But this algorithm is only applicable for directed graphs.


Intuition:
In this algorithm, the edges can be given in any order. The intuition is to relax all the edges for N-1( N = no. of nodes) times sequentially. After N-1 iterations, we should have minimized the distance to every node.
       
        wt
(u)------------->(v)

Let's consider the above graph with dist[u], dist[v], and wt. Here, wt is the weight of the edge and dist[u] signifies the shortest distance to reach node u found until now. Similarly, dist[v](maybe infinite) signifies the shortest distance to reach node v found until now. If the distance to reach v through u(i.e. dist[u] + wt) is smaller than dist[v], we will update the value of dist[v] with (dist[u] + wt). This process of updating the distance is called the relaxation of edges.

We will apply the above process(i.e. minimizing the distance to reach every node) N-1 times in the Bellman-Ford algorithm.

Two follow-up questions about the algorithm: 

Q1. Why do we need exact N-1 iterations?
     
    1          1         1         1
(0)------>(1)----->(2)------->(3)------->(4)
                      | u v wt
dist[3] + 1 < dist[4] | 3 4 1
dist[2] + 1 < dist[3] | 2 3 1
dist[1] + 1 < dist[2] | 1 2 1
dist[0] + 1 < dist[1] | 0 1 1


In the above graph, the algorithm will minimize the distance of the ith node in the ith iteration like dist[1] will be updated in the 1st iteration, dist[2] will be updated in the 2nd iteration, and so on. So we will need a total of 4 iterations(i.e. N-1 iterations) to minimize all the distances as dist[0] is already set to 0.
Note: Points to remember since, in a graph of N nodes we will take at most N-1 edges to reach from the first to the last node, we need exact N-1 iterations. It is impossible to draw a graph that takes more than N-1 edges to reach any node. 

Q2. How to detect a negative cycle in the graph?
    ➖ We know if we keep on rotating inside a negative cycle, the path weight will be decreased in every iteration. But according to our intuition, we should have minimized all the distances within N-1 iterations(that means, after N-1 iterations no relaxation of edges is possible). 

    ➖ In order to check the existence of a negative cycle, we will relax the edges one more time after the completion of N-1 iterations. And if in that Nth iteration, it is found that further relaxation of any edge is possible, we can conclude that the graph has a negative cycle. Thus, the Bellman-Ford algorithm detects negative cycles.

*/

vector<int> bellmanFord(int n, vector<vector<int>> &edges, int src){
    // Time complexity: O(N*E)
    // Space complexity: O(N)

    vector<int> distance(n, 1e8);
    distance[src] = 0;

    for (int times = 0; times < n - 1; times++){
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if (distance[u] != 1e8 && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
            }
        }
    }

    // Nth relaxation to check negative cycle (if it contains cycle means it still reducing)
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if (distance[u] != 1e8 && distance[u] + wt < distance[v]){
            return {-1};
        }
    }

    return distance;
}

int main(){
    int n = 5;
    int src=0;
    vector<vector<int>> edges = {
        {1,3,2},
        {4,3,-1},
        {2,4,1},
        {1,2,1},
        {0,1,5}};

    vector<int>ans=bellmanFord(n, edges, src);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}