#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.

Intuition: 
https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
https://takeuforward.org/data-structure/number-of-operations-to-make-network-connected-dsu-g-49/
*/

class DisjointSet{
public:
    vector<int> parent, size;
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
int makeConnected(int n, vector<vector<int>>& connections) {
    /* Time Complexity: O(E*4α)+O(N*4α) where E = no. of edges and N = no. of nodes. The first term is to calculate the number of extra edges and the second term is to count the number of components. 4α is for the disjoint set operation we have used and this term is so small that it can be considered constant.

    Space Complexity: O(2N) where N = no. of nodes. 2N for the two arrays(parent and size) of size N we have used inside the disjoint set.*/
    
    DisjointSet ds(n);
    int extraEdge=0;
    for(int i=0;i<connections.size();i++){
        int u=connections[i][0];
        int v=connections[i][1];

        if(ds.findUltimateParent(u) == ds.findUltimateParent(v)){
            extraEdge++;
        }else{
            ds.unionBySize(u,v);
        }
    }

    int totalParent=0;

    for(int i=0;i<n;i++){
        if(ds.parent[i]==i){
            totalParent++;
        }
    }

    // if a graph contains totalParent-1 extra-edges, 
    // we can make the graph connected with just totalParent-1 operations 
    //(where totalParent = no. of components of the graph).
    if(extraEdge>=totalParent-1){
        return totalParent-1;
    }
    else{
        return -1;
    }
}
int main(){
    int v = 9;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};
    cout<<(makeConnected(v,connections));
}