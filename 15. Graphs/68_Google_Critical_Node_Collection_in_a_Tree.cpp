#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Critical Node Collection in a Tree - Google 2025 

You are working on a Google infrastructure team that manages a large distributed system modeled as a general tree of interconnected servers. 
Each server is represented by a node numbered from 1 to N, and connections between servers form an undirected, acyclic structure. Some servers contain critical logs that must be collected during a system check.These servers are given in a set S. 
You begin the system check at server 1, and your goal is to: 
-> Start at node 1 
-> Visit every node in set S at least once 
-> Return back to node 1 after all required nodes have been visited 
-> In one move, you may travel from your current node to any of its adjacent nodes. 

Your task is to determine the minimum number of moves needed to complete this journey. 
Print a single integer — the minimum number of moves required to: Start at node 1 Visit all nodes in S Return back to node 1 


Example: N = 8 S = {5, 6} Edges: {{1, 2}, {2, 5}, {2, 3}, {2, 6}, {1, 4}, {4, 7}, {7, 8}}
Output: 6 
Explanation: Journey 1 → 2 → 5 → 2 → 6 → 2 → 1

               (1)-----------(2)----------(5)
                |            | \
                |            |  \
                |            |   \
               (4)          (3)   \
                |                  \ 
                |                  (6)
                |                   
                |
               (7)----------(8)                   
    
               


Core idea:
---------
For a given start node 'root':
    1. Root the tree at 'root'.
    2. DFS to determine which edges are part of the minimal subtree
      that covers all nodes in S.
    3. Every required edge must be traversed twice (down + up).
    => Minimum moves = 2 * (count_of_required_edges)



Explnation:
----------

1. Baseline Problem

Minimum moves to:
    1. Start at node 1
    2. Visit every node in S
    3. Return to node 1
    4. Move along tree edges (each move = 1 edge traversal)

This is a classical tree problem disguised as a system-traversal question.

The key idea:

You only need to traverse the minimal subtree that covers:
    the root (1)
    all nodes in S

That subtree is sometimes called the Steiner Tree on a Tree.

In a tree, the minimal Steiner tree covering nodes S ∪ {1} is simply the union of all LCA paths between each node in S and 1.

Once you identify this “required subtree,” the optimal traversal cost is:

Cost = 2 × (number of edges in the minimal required subtree)

Why?
    Every edge in this subtree must be traversed down and up in the worst case.
    There is no opportunity to avoid revisiting edges because you must return to the root and a tree has no alternative routes.

Thus:
Answer = 2 × |E_required_subtree|

1.1 How to compute the minimal required subtree
We root the tree at node 1.
Perform a DFS that returns whether the subtree contains any required S-node.
For each edge (u → v):
If the subtree of v contains at least one S node, we mark this edge as “required.”

Finally, count the number of required edges K, and answer is:

Result = 2 × K

Validate with given example

Tree:

1-2
2-5
2-3
2-6
1-4
4-7
7-8
S = {5,6}

Required edges are:

1–2
2–5
2–6

Total = 3 edges
Cost = 2 × 3 = 6

*/


// DFS returns true if this subtree contains any required S node
bool dfs(int u, int parent, int &total_edges, vector<vector<int>>&adj, vector<int>&s_mark){
    bool hasRequired = s_mark[u];

    for(auto v: adj[u]){
        if(v == parent) continue; // parent already visited so no need to compute again

        if(dfs(v, u, total_edges, adj, s_mark)){
            total_edges++;
            hasRequired = true;
        }
    }

    return hasRequired;
}


int compute_cost(int n, vector<int>s, vector<vector<int>>edges){
    // Time complexity: O(n)
    // Space complexity: O(n)

    // 1. creating adjacency list
    vector<vector<int>>adj(n+1);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2. Mark required server node as true and remaining will be false
    vector<int>s_mark(n+1,0);
    for(int i=0;i<s.size();i++){
        s_mark[s[i]] = 1;
    }

    int total_edges = 0;
    int starting_node = 1;
    int parent = -1;

    // 3. get total edges
    dfs(starting_node, parent, total_edges, adj, s_mark);

    // fianl answer
    return 2 * total_edges;
}

int main(){
    int n = 8;
    vector<int>s={5,6};
    vector<vector<int>>edges={{1, 2}, {2, 5}, {2, 3}, {2, 6}, {1, 4}, {4, 7}, {7, 8}};

    int ans = compute_cost(n,s,edges);
    cout<<ans<<endl;

}
