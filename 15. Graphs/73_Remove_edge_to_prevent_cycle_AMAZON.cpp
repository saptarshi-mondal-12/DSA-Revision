#include<bits/stdc++.h>
using namepsace std;


/* Q. Redundant Connection - AMAZON


In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 


-----Intuition ----------------------------

The intuition is that before adding any edge, I want to check whether the two nodes are already connected.

If there is already a path between u and v, then adding the edge (u, v) will create a cycle. Therefore, that edge is the redundant connection.

I process the edges one by one.

For each edge (u, v), I use DFS to check whether I can already reach v starting from u.

If there is no existing path, I safely add the edge to the graph.

If a path already exists, adding this edge will create a cycle, so I return that edge.

For example, after adding [1,2] and [1,3], there is already a path from 2 to 3 through 1:

2 -> 1 -> 3

So when I encounter [2,3], I know that adding it will create a cycle:

2 -> 1 -> 3 -> 2

Therefore, [2,3] is the redundant connection.

The important idea is: "Before adding an edge, check whether its two endpoints are already connected. If they are, that edge creates the cycle."
*/

class Solution {
public:
    bool dfs(int src, int target, vector<int>& visited,
             vector<vector<int>>& adj) {

        if (src == target)
            return true;

        visited[src] = 1;

        for (int node : adj[src]) {
            if (!visited[node]) {
                if (dfs(node, target, visited, adj))
                    return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<int> visited(n + 1, 0);

            // Is there already a path from u to v?
            if (dfs(u, v, visited, adj)) {
                return {u, v};
            }

            // No path exists, so safely add this edge
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
