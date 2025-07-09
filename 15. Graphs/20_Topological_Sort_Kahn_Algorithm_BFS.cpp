#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Kahn's Algorithm | Topological Sort Algorithm | BFS

Definition : Topological Sort Algorithm / Kahn's Algorithm 

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

If there is an edge between u and v (u--->v), u appears before v in the linear ordering.

Linear ordering of vertices such that if there is a edge between u and v (u-->v) u appear before v in the ordering

NOTE: It is only applicable to DAG (Directed Acyclic Graph) (does'nt have a cycle)



  (5)━━━━━►(0)◄━━━━━(4)
   ┃                 ┃  
   ┃                 ┃
   ▼                 ▼ 
  (2)━━━━━►(3)━━━━━►(1)

Output: 5, 4, 2, 3, 1, 0
Explanation: A graph may have multiple topological sortings. 
The result is one of them. The necessary conditions 
for the ordering are:
According to edge 5 -> 0, node 5 must appear before node 0 in the ordering.
According to edge 4 -> 0, node 4 must appear before node 0 in the ordering.
According to edge 5 -> 2, node 5 must appear before node 2 in the ordering.
According to edge 2 -> 3, node 2 must appear before node 3 in the ordering.
According to edge 3 -> 1, node 3 must appear before node 1 in the ordering.
According to edge 4 -> 1, node 4 must appear before node 1 in the ordering.


Q. Why Directed, why not for undirected ?
because (1)━━━━━(2), [1 to 2] and [2 to 1]
it is bidirectional, linear ordering cannot have such that 1 appear before 2 at the same time 2 appear before 1 because edges are bidirectional. theeby it has to be a directecd graph.

    Case 1 (If the edges are undirected): 
    If there is an undirected edge between node u and v, it signifies that there is an edge from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). But according to the definition of topological sorting, it is practically impossible to write such ordering where u appears before v and v appears before u simultaneously. So, it is only possible for directed edges.

    case 2: Case 2(If the directed graph contains a cycle): 

    (1)━━━━━>(2)
     ^      /
      \    /
       \  v
        (3)

    If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, for edge 2->3, node 2 must appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear ordering. But such ordering is not possible as there exists a cyclic dependency in the graph. Thereby, topological sorting is only possible for a directed acyclic graph.


Initial Configuration:

Indegree Array: Initially all elements are set to 0. Then, We will count the incoming edges for a node and store it in this array. For example, if indegree of node 3 is 2, indegree[3] = 2.

Queue: As we will use BFS, a queue is required. Initially, the node with indegree 0 will be pushed into the queue.

Answer array: Initially empty and is used to store the linear ordering.


Q. Practice Question: Q.52
https://www.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1
*/

vector<int> topoSort(int n, vector<vector<int>>&edges){
    // Time complexity: O(V+E), where V = no. of nodes and E = no. of edges.
    // Space Complexity: O(N) + O(N) = O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS

    // creating adjacency list;
    vector<vector<int>> adjacency_List(n);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjacency_List[u].push_back(v);
    }

    // indegree - no of incomming edges
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++){
        for (auto it : adjacency_List[i]){
            indegree[it]++;
        }
    }

    // Insert all node with indegree 0 
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()){
        int node = q.front();
        q.pop();

        // Put node is in your topo sort
        topo.push_back(node);

        for (auto it : adjacency_List[node]){
            indegree[it]--;
            if (indegree[it] == 0){
                q.push(it);
            }
        }
    }

    return topo;
}

int main(){
    int n = 6;
    vector<vector<int>> edges = {
        {5,0}, {4,0}, {5,2}, {4,1}, {2, 3}, {3, 1}};
    vector<int> ans = topoSort(n, edges);

    for (auto node : ans){
        cout << node << " ";
    }
}