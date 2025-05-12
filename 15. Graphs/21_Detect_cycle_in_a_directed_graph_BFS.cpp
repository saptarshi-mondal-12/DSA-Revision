#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Detect cycle in a directed graph -----> | Kahn's Algorithm | BFS

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

We know that topo sorts are only applicable on DAG (directed acyclic graph). if graph has a cycle it won't work.

Q. How do we detect a cycle in directed graph ?
Ans: Since i know topo sort is not possible for graph that has a cycle, I'll still try to apply topological sort for the graph. 
If the topological sort produce less than n elements, then we can definetely say it has a cycle and if topological sort produce exactly n elements, then we can can definetely say it does not contains cycle. 


what is toposort -> it is a linear ordering of n vertices, So if u not produce toposort of n size we can definetely say their is a problem and the problem is there is a cycle. 

NOTE: 
1. If toposort has exactly n elements then we can say it is a DAG (directed acyclic graph) means no cycle.

2. If toposort has less than n elements then we can say it is a DCG (directed cyclic graph) means there is a cycle.
*/

bool isCyclic(int n, vector<vector<int>> &edges){
    // Time complexity: O(V+E) for directed graph
    // Space complexity: O(N) + O(N) ~ O(2N) = indegree and queue

    // creating adjacency list;
    vector<vector<int>> adjacency_List(n);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjacency_List[u].push_back(v);
    }

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++){
        for (auto it : adjacency_List[i])
        {
            indegree[it]++;
        }
    }

    // Pushing all 0 indegree to queue
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        // node is in your topo sort
        // so please remove it from the indegree

        for (auto it : adjacency_List[node]){
            indegree[it]--;
            if (indegree[it] == 0){
                q.push(it);
            }
        }
    }

    // if count is < n -> means it contains cycle 
    if (count < n){
        return true;
    }
    return false;
}

int main(){
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 0},
        {2, 3}};
    cout << isCyclic(n, edges);
}