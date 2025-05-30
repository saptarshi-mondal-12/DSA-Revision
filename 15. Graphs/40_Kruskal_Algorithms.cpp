#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Kruskal's Algorithms

Definition: 
Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected, and weighted graph.

Kruskal's Algorithm selects edges in increasing order of weight and adds them to the MST if they do not form a cycle, until the MST includes all vertices.



Given a weighted, undirected, and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.


Input Format: V = 5, edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}}
Result: 16
Explanation: The minimum spanning tree for the given graph is drawn below:
MST = {(0, 1), (0, 3), (1, 2), (1, 4)}


Input Format: V = 5, edges = { {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}}
Result: 5
Explanation: The minimum spanning tree is drawn below:
MST = {(0, 2), (1, 2), (2, 3), (3, 4)}



Intuition: ----------------------------------------------------------------------------

There are two ways to find the minimum spanning tree for a given weighted and undirected graph. i.e. Prim's algorithm & Kruskal's algorithms.

We will be implementing Kruskal’s algorithm using the Disjoint Set data structure

Approach: 

Now, we know Disjoint Set provides two methods named findUPar()(This function helps to find the ultimate parent of a particular node) and Union(This basically helps to add the edges between two nodes). To know more about these functionalities, do refer to the article on Disjoint Set.

The algorithm steps are as follows:

1. First, we need to extract the edge information(if not given already) from the given adjacency list in the format of (wt, u, v) where u is the current node, v is the adjacent node and wt is the weight of the edge between node u and v and we will store the tuples in an array.

2. Then the array must be sorted in the ascending order of the weights so that while iterating we can get the edges with the minimum weights first.

3. After that, we will iterate over the edge information, and for each tuple, we will apply the  following operation:
    
    a. First, we will take the two nodes u and v from the tuple and check if the ultimate parents of both nodes are the same or not using the findUPar() function provided by the Disjoint Set data structure.
    
    b. If the ultimate parents are the same, we need not do anything to that edge as there already exists a path between the nodes and we will continue to the next tuple.
    
    c. If the ultimate parents are different, we will add the weight of the edge to our final answer(i.e. mstWt variable used in the following code) and apply the union operation(i.e. either unionBySize(u, v) or unionByRank(u, v)) with the nodes u and v. The union operation is also provided by the Disjoint Set.

4. Finally, we will get our answer (in the mstWt variable as used in the following code) successfully.

*/

class DisjointSet{
    vector<int> parent, size;

public:
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if (ulp_u == ulp_v){
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> edges){

    /* Time Complexity: O(N+E) + O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(N+E) for extracting edge information from the adjacency list. O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

    Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge information. And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N).*/
    
    vector<pair<int,pair<int,int>>> adjacencyList(V);
    for (int i = 0; i < V; i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];

        // {wt, {node, adjacentNode}}
        adjacencyList.push_back({wt,{u,v}});
    }

    sort(adjacencyList.begin(), adjacencyList.end());
    
    DisjointSet ds(V);

    int mstWt = 0;
    for (auto it : adjacencyList) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }
    return mstWt;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};
    cout<<spanningTree(V,edges);
}