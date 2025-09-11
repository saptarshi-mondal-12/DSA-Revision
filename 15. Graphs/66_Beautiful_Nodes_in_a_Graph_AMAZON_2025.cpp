#include<bits/stdc++.h>
using namespace std;

/* Q. Beautiful Nodes in a Graph - AMAZON 2025

We are given an n × n adjacency matrix of a directed graph:

    1. matrix[i][j] = 1 → Node i has an edge to node j.
    2. A node is beautiful if:
        a) It is connected to all other nodes (outgoing edges to every other node).
        b) No node is connected to it (no incoming edges from any node).

We need to return all such nodes.

*/

vector<int> beautifulNodes(vector<vector<int>>& matrix){
    // Time complexity: O(nxn) + O(n) + O(n) + O(n) = O(n^2)
    // Space complexity: O(nxn) + O(n) + O(n) = O(n^2)

    // no of nodes
    int n = matrix.size();

    // result => stores beautiful node 
    vector<int> result;

    // Adjacency List
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }

    // Calculate indegree
    vector<int> indegree(n, 0);
    for(int i=0;i<n;i++){
        for (auto it : adj[i]){
            indegree[it]++;
        }
    }


    // Calculate outdegree
    vector<int> outdegree(n, 0);
    for(int i=0;i<n;i++){
        outdegree[i] = adj[i].size();
    }



    // Calculate beautiful node 
    // if indegree = 0 means No node is connected to it (no incoming edges from any node)
    // outdegree = n-1 connected to all other nodes except itself i.e n-1 nodes (outgoing edges to every other node)
    for(int i=0;i<n;i++){
        if(indegree[i] == 0 && outdegree[i] == n-1){
            result.push_back(i);
        }
    }

    return result;

}

int main(){
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 0, 0}
    };

    vector<int> result = beautifulNodes(matrix);
    for(auto it: result){
        cout<<it<<" ";
    }
}