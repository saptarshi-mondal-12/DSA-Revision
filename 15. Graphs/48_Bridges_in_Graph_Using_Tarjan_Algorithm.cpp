#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Bridges in Graph - Tarjan's Algorithm

Q. What is bridge?
Ans: A bridge is an edge in a graph whose removal, the graph gets broken down into 2 or more components is known as bridge.



Q. Critical Connections in a Network

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]


----------------------------------------------------------------------------------------------------------

Note: We are not considering the parent’s insertion time during calculating the lowest insertion time as we want to check if any other path from the node to the parent exists excluding the edge we intend to remove.


https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/

*/

void dfs(int node, int parent, vector<int> &visited, vector<vector<int>> &adjacencyList, vector<int> &timeOfInsertion, vector<int> &low, int &timer, vector<vector<int>> &bridge){
    visited[node] = 1;
    timeOfInsertion[node] = timer;
    low[node] = timer;
    timer++;
    for (auto it : adjacencyList[node]){
        if (it == parent)
            continue;
        if (visited[it] == 1){
            low[node] = min(low[node], low[it]);
        }
        else{
            dfs(it, node, visited, adjacencyList, timeOfInsertion, low, timer, bridge);
            low[node] = min(low[node], low[it]);

            // can this node to it is a bridge, if it is greater then it is a bridge
            if (low[it] > timeOfInsertion[node]){
                bridge.push_back({it, node});
            }
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections){
    /* Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.

    Space Complexity: O(V+2E) + O(3V), where V = no. of vertices, E = no. of edges. O(V+2E) to store the graph in an adjacency list and O(3V) for the three arrays i.e. tin, low, and vis, each of size V */


    vector<vector<int>> adjacencyList(n);
    for (int i = 0; i < connections.size(); i++){
        int u = connections[i][0];
        int v = connections[i][1];
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<int> timeOfInsertion(n, 0);
    vector<int> low(n, 0);
    vector<vector<int>> bridge;
    int timer = 1;
    dfs(0, -1, visited, adjacencyList, timeOfInsertion, low, timer, bridge);
    return bridge;
}

int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };

    vector<vector<int>> bridges = criticalConnections(n, connections);
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
}