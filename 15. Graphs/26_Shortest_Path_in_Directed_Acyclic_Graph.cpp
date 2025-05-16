#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Shortest Path in Directed Acyclic Graph (DAG)

Given a DAG, find the shortest path from the source to all other nodes in this DAG. In this problem statement, we have assumed the source vertex to be ‘0’. You will be given the weighted edges of the graph.
Given Edges format - (u,v,weight) u-->v


Input: n = 6, m= 7
edges =[[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]] 
Output: 0 2 3 6 1 5

Input: n = 7, m= 8
Edges =[[0,4,2],[0,5,3],[5,4,1],[4,6,3],[4,2,1],[6,1,2],[2,3,3],[1,3,1]]
Output: 0 7 3 6 2 3 5


         3         2
    (4)━━━━━►(6)━━━━━━►(1)
    ▲ ▲\                ┃
 2 /  ┃ \               ┃
  /   ┃  \ 1            ┃
(0)   ┃   \             ┃ 1
  \   ┃1   \            ┃
 3 \  ┃     \           ┃
    ▼ ┃      ▼          ▼
    (5)     (2)━━━━━━━►(3)
                3


Approach: -----------------------------------------------------------------------

We will calculate the shortest path in a directed acyclic graph by using topological sort. Topological sort can be implemented in two ways- BFS and DFS. Here, we will be implementing using the DFS technique. Depth First Search, DFS is a traversal technique where we visit a node and then continue visiting its adjacent nodes until we reach the end point, i.e., it keeps on moving in the depth of a particular node and then backtracks when no further adjacent nodes are available. 

Initial configuration:
    
1. Adjacency List: Create an adjacency list of the formed vector of pairs of size ‘N’, where each index denotes a node ‘u’ and contains a vector that consists of pairs denoting the adjacent nodes ‘v’ and the distance to that adjacent node from initial node ‘u’.

2. Visited Array: Create a visited array and mark all the indices as unvisited (0) initially.
Stack: Define a stack data structure to store the topological sort.

3. Distance Array: Initialise this array by Max integer value and then update the value for each node successively while calculating the shortest distance between the source and the current node.

The shortest path in a directed acyclic graph can be calculated by the following steps:

1. Perform topological sort on the graph using BFS/DFS and store it in a stack. In order to get a hang of how the Topological Sort works, you can refer to this article for the same. 

2. Now, iterate on the topo sort. We can keep the generated topo sort in the stack only, and do an iteration on it, it reduces the extra space which would have been required to store it. Make sure for the source node, we will assign dist[src] = 0. 

3. For every node that comes out of the stack which contains our topo sort, we can traverse for all its adjacent nodes, and relax them. 

4. In order to relax them, we simply do a simple comparison of dist[node] + wt and dist[adjNode]. Here dist[node] means the distance taken to reach the current node, and it is the edge weight between the node and the adjNode. 

5. If (dist[node] + wt < dist[adjNode]), then we will go ahead and update the distance of the dist[adjNode] to the new found better path. 

6. Once all the nodes have been iterated, the dist[] array will store the shortest paths and we can then return it.
*/

void dfs(int node, vector<int>&visited, vector<vector<pair<int,int>>>&adjacencyList, stack<int> &st){
    // 1. Mark node as visited 
    visited[node]=1;

    // Traverse all its neighbours
    for(auto it: adjacencyList[node]){
        // if the neighbour is not visited
        int v = it.second;
        if(!visited[v]){
            dfs(v, visited, adjacencyList, st);
        }
    }
    st.push(node);
}

vector<int>shortestPath(int n, vector<vector<int>>edges){
    // Time complexity: O(N+E) {for the topological sort} + O(N+E) {for relaxation of vertices, each node and its adjacent nodes get traversed} = O(N+E).

    // Space complexity: O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2E) {for the adjacency list} ~ O(N+E) .

    // 1. Creating adjacency list
    vector<vector<pair<int,int>>> adjacencyList(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int weight=edges[i][2];

        adjacencyList[u].push_back({weight, v});
    }

    // 2. Performing topological sort using DFS
    vector<int> visited(n,0);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, visited, adjacencyList, st);
		}
	}

    // 3. Further, we declare a vector ‘dist’ in which we update the value of the nodes, distance from the source vertex after relaxation of a particular node.

    int src=0;
    vector<int>distance(n, 1e9);

    // Make distance of source node to 0 (because distance between source to source is 0)
    distance[src]=0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        for (auto it: adjacencyList[node]) {
            int wt = it.first;
            int v = it.second;

            if (distance[node] + wt < distance[v]) {
                distance[v] = wt + distance[node];
            }
        }
    }

    // if node is unreachable from source node, putting -1
    for (int i = 0; i < n; i++) {
        if (distance[i] == 1e9){
            distance[i] = -1;
        }
    }
    return distance;
}

int main(){
    int n = 7;
    vector<vector<int>> edges= {{0,4,2},{0,5,3},{5,4,1},{4,6,3},{4,2,1},{6,1,2},{2,3,3},{1,3,1}};

    vector<int>ans=shortestPath(n,edges);
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
