#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Topological Sort Algorithm

Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.

Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Example 1:

Input: V = 6, E = 6

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

The above result satisfies all the necessary conditions. 
[4, 5, 2, 3, 1, 0] is also one such topological sorting that satisfies all the conditions.





Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are connected through directed edges and the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 

The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.

Now, let's understand Why topological sort only exists in DAG:

    Case 1: (If the edges are undirected): If there is an undirected edge between node u and v, it signifies that there is an edge from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). But according to the definition of topological sorting, it is practically impossible to write such ordering where u appears before v and v appears before u simultaneously. So, it is only possible for directed edges.

    Case 2: (If the directed graph contains a cycle):

    (1)━━━━━>(2)
     ^      /
      \    /
       \  v
        (3)
        
    If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, for edge 2->3, node 2 must appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear ordering. But such ordering is not possible as there exists a cyclic dependency in the graph. Thereby, topological sorting is only possible for a directed acyclic graph.

    

Approach: 

We will be solving it using the DFS traversal technique. DFS goes in-depth, i.e., traverses all nodes by going ahead, and when there are no further nodes to traverse in the current path, then it backtracks on the same path and traverses other unvisited nodes.

The algorithm steps are as follows:
    1. We must traverse all components of the graph.
    2. Make sure to carry a visited array(all elements are initialized to 0) and a stack data structure, where we are going to store the nodes after completing the DFS call.
    3. In the DFS call, first, the current node is marked as visited. Then DFS call is made for all its adjacent nodes.
    4. After visiting all its adjacent nodes, DFS will backtrack to the previous node and meanwhile, the current node is pushed into the stack.
    5. Finally, we will get the stack containing one of the topological sortings of the graph.
*/

void dfs(int node, vector<int>&visited, vector<vector<int>>&adjacency_List, stack<int> &st){
    // 1. Mark node as visited 
    visited[node]=1;

    // Traverse all its neighbours
    for(auto it: adjacency_List[node]){
        // if the neighbour is not visited
        if(!visited[it]){
            dfs(it, visited, adjacency_List, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int n, vector<vector<int>>&edges) {
    // Time Complexity: O(N+E)+O(N), where N = no. of nodes and E = no. of edges. There can be at most N components. So, another O(N) time complexity.
    
    // Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for the visited array and the stack carried during DFS calls and O(N) for recursive stack space, where N = no. of nodes.


    // creating adjacency list;
    vector<vector<int>> adjacency_List(n);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjacency_List[u].push_back(v);
    }

    vector<int> visited(n,0);
	stack<int> st;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i, visited, adjacency_List, st);
		}
	}

	vector<int> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}

int main() {
    int n = 6;
	vector<vector<int>> edges = {{5,0}, {4,0}, {5,2}, {4,1}, {2, 3}, {3, 1}};
	vector<int> ans = topoSort(n, edges);

	for (auto node : ans) {
		cout << node << " ";
	}
}