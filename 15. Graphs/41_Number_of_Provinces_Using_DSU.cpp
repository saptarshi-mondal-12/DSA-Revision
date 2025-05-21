#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/* Q. Number of Provinces

There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

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

int findCircleNum(vector<vector<int>> &isConnected){
    int n = isConnected.size();
    DisjointSet ds(n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (isConnected[i][j] == 1){
                ds.unionBySize(i, j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        if (ds.parent[i] == i){
            count++;
        }
    }
    return count;
}

int main(){
    vector<vector<int>> isConnected{ 
        {1,1,1,0},
        {1,1,1,0},
        {1,1,1,0},
        {0,0,0,1}
    };
    cout<<findCircleNum(isConnected)<<endl;
}