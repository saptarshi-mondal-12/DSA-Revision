#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Disjoint Set | Union by Rank | Union by Size | Path Compression


Q. Why we need a Disjoint Set data structure?
Ans: Given two components of an undirected graph

(1)━━━━━━(2)━━━━━━(3)━━━━━━(4)

(5)━━━━━━(6)━━━━━━(7)

The question is whether node 1 and node 5 are in the same component or not.

Now, in order to solve this question we can use either the DFS or BFS traversal technique like if we traverse the components of the graph we can find that node 1 and node 5 are not in the same component. This is actually the brute force approach whose time complexity is O(N+E)(N = no. of nodes, E = no. of edges). But using a Disjoint Set data structure we can solve this same problem in constant time.

The disjoint Set data structure is generally used for dynamic graphs. 


Q. What is path compression?
Basically, connecting each node in a particular path to its ultimate parent refers to path compression.

Q. How the time complexity reduces:
Before path compression, if we had tried to find the ultimate parent for node 4, we had to traverse all the way back to node 1 which is basically the height of size logN. But after path compression, we can easily access the ultimate parent with a single step. Thus the traversal reduces and as a result the time complexity also reduces.


Follow-up question:

Q. In the union by rank method, why do we need to connect the smaller rank to the larger rank?
Ans: 


https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/

Time Complexity:  The time complexity is O(4 alpha) which is very small and close to 1. So, we can consider 4 as a constant.
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

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
}