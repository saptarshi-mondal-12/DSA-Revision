#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Detect cycle in a directed graph -----> DFS

Given a directed graph with V vertices and E edges, check whether it contains any cycle or not.

Input: N = 10, E = 11
Output: true (8,9,10 is a cycle )

  (1)━━━━━►(2)━━━━━►(3)━━━━━►(4)
           ▲         ┃        ┃
          /          ┃        ┃
         /           ▼        ▼
        /           (7)━━━━━►(5)━━━━━►(6)
       (8)
       / ▲
      /   \
     ▼     \
    (9)━━━►(10)


Input: n = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]
   (1)━━►(2)
    ▲   ▲ ┃   
    ┃  /  ┃  
    ┃ ▼   ▼ 
   (0)   (3)

Output: true
Explanation: The diagram clearly shows a cycle 0 → 2 → 0

Intuition:-------------------------------------------------------------

  (1)━━━━━►(2)━━━━━►(3)━━━━━►(4)
           ▲         ┃        ┃
          /          ┃        ┃
         /           ▼        ▼
        /           (7)━━━━━►(5)━━━━━►(6)
       (8)
       / ▲
      /   \
     ▼     \
    (9)━━━►(10)

In a Directed Cyclic Graph, during traversal, if we end up at a node, which we have visited previously in the path, that means we came around a circle and ended up at this node, which determines that it has a cycle. Previously, we have learned a similar technique to detect cycles in an Undirected Graph (using DFS). In that method, the algorithm returns true, if it finds an adjacent node that is previously visited and not a parent of the current node. But the same algorithm will not work in this case. Let’s understand why this happens considering the below graph.

    You can also look at the GIF below, in case you fail to understand the below points. 
    
    Let’s start DFS from node 1. It will follow the path 1->2->3->4->5->6, all the nodes including 5 will be visited as marked. 
    
    As there are no further nodes after node 6, DFS will backtrack to node 3 and will follow the path: 3->7->5->6. It followed this path because this path was left to be explored. 
    
    Reaching node 7, the adjacent node 5 can be found previously visited, but ideally, it should not have been visited, as we did not visit this node in a continuous path. At this point, the algorithm will conclude that this is a cycle and will return true but this is not a cycle as node 5 has been visited twice following two different paths.
    
    This would have been true if the nodes are connected to undirected edges. But as we are dealing with directed edges this algorithm fails to detect a cycle. 
    
    Due to the above reason, we need to think of an algorithm, which keeps a track of visited nodes, in the traversal only. 

So the intuition is to reach a previously visited node again on the same path. If it can be done, we conclude that the graph has a cycle.

Note: If a directed graph contains a cycle, the node has to be visited again on the same path and not through different paths.

*/

bool dfsCheck(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> &pathVis){
    visited[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node]){
        // when the node is not visited
        if (!visited[it]){
            if (dfsCheck(it, adj, visited, pathVis) == true)
                return true;
        }
        // if the node has been previously visited
        // but it has to be visited on the same path
        else if (pathVis[it]){
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}
bool isCyclic(int n, vector<vector<int>> &edges){
    // Time complexity: O(N + E) Because it is a directed graph i.e E not 2E
    // Space complexity: O(N) + O(N) + O(N)

    // creating adjacency list;
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<int> visited(n, 0);
    vector<int> pathVis(n, 0);


    for (int i = 0; i < n; i++){
        if (!visited[i]){
            if (dfsCheck(i, adj, visited, pathVis) == true)
                return true;
        }
    }
    return false;
}

int main(){
    int n=4;
    vector<vector<int>> edges={
        {0,1},
        {0,2},
        {1,2},
        {2,0},
        {2,3}
    };

    cout<<isCyclic(n,edges);
}