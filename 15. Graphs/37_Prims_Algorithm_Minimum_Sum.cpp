#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Prim's Algorithm 

Definition:
Prim's algorithm is a greedy algorithm which helps us to find minimum spanning tree (MST) of a connected, weighted, undirected graph.

🔶 Intuition: 
The intuition behind Prim’s Algorithm is based on the greedy technique. At each step, we greedily choose the smallest edge that connects a visited node to an unvisited node.
We use a min-heap (priority queue) to always pick the next minimum-weight edge. This process is repeated until all nodes are included in the tree. By doing this, we ensure that we build the Minimum Spanning Tree (MST) without forming cycles and with the minimum possible total edge weight. The idea is to grow the MST step by step, always choosing the cheapest possible option.

If a cycle is present, it’s no longer a tree — it becomes a graph with a cycle, which violates the basic definition of a tree.

If you ever form a cycle while building the MST, you can always remove one edge from that cycle, and the graph will still remain connected but with a smaller or equal total weight — meaning the cycle was unnecessary.



Problem Statement: ------> (Minimum Sum)
Given a weighted, undirected, and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree. (Sometimes it may be asked to find the MST as well, where in the MST the edge-informations will be stored in the form {u, v}(u = starting node, v = ending node).)

Input Format: V = 5, edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}}
Result: 16
Explanation: The minimum spanning tree for the given graph is drawn below:
MST = {(0, 1), (0, 3), (1, 2), (1, 4)}


Input Format: V = 5, edges = { {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}}
Result: 5
Explanation: The minimum spanning tree is drawn below:
MST = {(0, 2), (1, 2), (2, 3), (3, 4)}

*/

int spanningTree(int v, vector<vector<int>> edges){
    /* Time compleixty: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
    
    The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE). 

    Space complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most. */


    vector<vector<pair<int,int>>> adjacencyList(v);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adjacencyList[u].push_back({wt, v});
        adjacencyList[v].push_back({wt, u});
    }
    

    vector<int> vis(v, 0);

    // {wt, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty()){
        int wt=pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node] == 1)
            continue;
        
        // add it to the mst
        vis[node] = 1;
        sum += wt;
        for (auto it : adjacencyList[node]){
            int edW = it.first;
            int adjNode = it.second;
            if (!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}


int main(){
    int v = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    int sum = spanningTree(v, edges);
    cout << sum << endl;
}