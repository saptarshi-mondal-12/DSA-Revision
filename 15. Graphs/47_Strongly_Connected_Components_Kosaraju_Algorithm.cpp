#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Strongly Connected Components - Kosaraju's Algorithm 

✅ Definition Kosaraju's Algorithm: 
Kosaraju’s Algorithm is an efficient way to find all Strongly Connected Components (SCCs) in a directed graph.
It is only applicable for directed graph.



✅ Strongly Connected Component(SCC):
A component is called a Strongly Connected Component(SCC) only if, for every possible pair of vertices (u, v) in that component is reachable from each other means u is reachable to v and v is reachable to u.

In a directed graph G=(V,E), a strongly connected component is a subset of vertices such that for every pair of vertices there is a path from u to v, and from v to 𝑢


   (0)◄━━━(2)━━━━►(3)━━━━━━━►(4)━━━►(7)
    ┃     ▲                   ┃ ▲    ▲
    ┃    /                    ┃  \   ┃
    ┃   /                     ┃   \  ┃
    ▼  /                      ▼    \ ┃     
    (1)                      (5)━━━►(6)


(0,1,2), (3), (4,5,6), and (7).


If we take 1st SCC in the above graph, we can observe that each node is reachable from any of the other nodes. For example, if take the pair (0, 1) from the 1st SCC, we can see that 0 is reachable from 1 and 1 is also reachable from 0. Similarly, this is true for all other pairs of nodes in the SCC like (0,2), and (1,2). But if we take node 3 with the component, we can notice that for pair (2,3) 3 is reachable from 3 but 2 is not reachable from 3. So, the first SCC only includes vertices 0, 1, and 2.

By definition, a component containing a single vertex is always a strongly connected component. For that vertex 3 in the above graph is itself a strongly connected component.

By applying this logic, we can conclude that the above graph contains 4 strongly connected components like (0,1,2), (3), (4,5,6), and (7).

To find the strongly connected components of a given directed graph, we are going to use Kosaraju’s Algorithm.


✅ Why Strongly Connected Components (SCCs) are Important?
Ans: Understanding SCCs is crucial for various applications such as:
    1. Network Analysis: Identifying clusters of tightly interconnected nodes.
    2 Optimizing Web Crawlers: Determining parts of the web graph that are closely linked.
    3. Dependency Resolution: In software, understanding which modules are interdependent.



✅ Intuition: 

The intuition is to stop one SCC from reaching another SCC.

If we reverse all edges in a graph, the Strongly Connected Components (SCCs) remain the same, but the reachability between them changes. So, Reversal of edges will stop you to go next SCCs. So that dfs will happen in individual strongly connected components.

If the second DFS runs n times, we have found n SCCs.



✅ Steps:

1. Sort all the nodes according to their finishing time:
    To sort all the nodes according to their finishing time, we will start DFS from node 0 and while backtracking in the DFS call we will store the nodes in a stack data structure. The nodes in the last SCC will finish first and will be stored in the last of the stack. After the DFS gets completed for all the nodes, the stack will be storing all the nodes in the sorted order of their finishing time.

2. Reverse all the edges of the entire graph (Reverse the graph):
    Now, we will create another adjacency list and store the information of the graph in a reversed manner.

3. Perform the DFS and count the no. of different DFS calls to get the no. of SCC:
    Now, we will start DFS from the node which is on the top of the stack and continue until the stack becomes empty. For each individual DFS call, we will increment the counter variable by 1. We will get the number of SCCs by just counting the number of individual DFS calls as in each individual DFS call, all the nodes of a particular SCC get visited.

4. Finally, we will get the number of SCCs in the counter variable. If we want to store the SCCs as well, we need to store the nodes in some array during each individual DFS call in step 3.


-------------------------------------------------------------------------------------------------------
Note: 
    1. The first step is to know, from which node we should start the DFS call.
    2. The second step is to make adjacent SCCs unreachable and to limit the DFS traversal in such a way, that in each DFS call, all the nodes of a particular SCC get visited.
    3. The third step is to get the numbers of the SCCs. In this step, we can also store the nodes of each SCC if we want to do so.

Note: The sorting of the nodes according to their finishing time is very important. By performing this step, we will get to know where we should start our DFS calls. The top-most element of the stack will finish last and it will surely belong to the SCC1. So, the sorting step is important for the algorithm.


--------------------------------------------------------------------------------------------------------
In an interview, we can expect two types of questions from this topic:
    Q.Find the number of strongly connected components of a given graph.
    Q.Print the strongly connected components of a given graph.


-------------------------------------------------------------------------------------------------------
Q. Strongly Connected Components 

Problem Statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Input: adj[][] = [[2, 3], [0], [1], [4], []]
Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 

Input: adj[][] = [[1], [2], [0]]
Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.


Input: adj[][] = [[1], []]
Output: 2



https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/

*/
void dfs(int node, vector<int>&visited, vector<vector<int>> &adj, stack<int> &st){
    visited[node]=1;
    for(auto it: adj[node]){
        if (!visited[it]) {  
            dfs(it, visited, adj, st);
        }
    }
    st.push(node);
}

void dfs3(int node, vector<int>&visited, vector<vector<int>> &reverseAdj, vector<int> &component){
    visited[node]=1;
    component.push_back(node); // collect node in current SCC
    for(auto it: reverseAdj[node]){
        if (!visited[it]){
            dfs3(it, visited, reverseAdj, component);
        }
    }
}

int kosaraju(vector<vector<int>> &adj) {

    /* Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.

    Space Complexity: O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list*/

    int n=adj.size();

    // step 1: Sort all the nodes according to their finishing time
    vector<int>visited(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, visited, adj, st);
        }
    }

    // step 2: Reverse all the edges of the entire graph (Reverse the graph)
    vector<vector<int>> reverseAdj(n);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (auto it : adj[i]) {
            // i -> it
            // it -> i
            reverseAdj[it].push_back(i);
        }
    }

    // step 3: Perform the DFS and count the no. of different DFS calls to get the no. of SCC:

    int scc = 0;
    vector<vector<int>> allSCCs;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            scc++;
            vector<int> component;
            dfs3(node, visited, reverseAdj, component);
            allSCCs.push_back(component);
        }
    }

    // printing all SCCs
    cout << "Strongly Connected Components are:\n";
    for (auto& component : allSCCs) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return scc;
}

int main() {
    int n=8;
    vector<vector<int>> edges = {
        {0, 1}, {2, 0},
        {1, 2}, {2, 3},
        {3, 4}, {4,7}, {4,5},{5,6},{6,4},{6,7}};

    vector<vector<int>> adj(n);
    for (auto it: edges) {
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
    }

    cout << "The number of strongly connected components is: " << kosaraju(adj) <<endl;
}