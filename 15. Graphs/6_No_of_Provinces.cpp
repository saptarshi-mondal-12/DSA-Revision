#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Number of Provinces or Number of Connected Components in an Undirected Graph

Problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Input: 
   (1)-(2)
    |  /
    | / 
   (3)      (4)
          

Output: 2


--------------------------------------------------------------------------------------------

Follow up question - Soln Q.62

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1


*/ 
void dfs(int node, vector<vector<int>>adjacencyList, int visited[]){
    // 1. Mark node as visited 
    visited[node]=1;

    // Traverse all its neighbours
    for(auto it: adjacencyList[node]){
        // if the neighbour is not visited
        if(!visited[it]){
            dfs(it, adjacencyList, visited);
        }
    }
}

int numProvinces(vector<vector<int>> adj){
   // Time Complexity: O(N) + O(N+2E), Where O(N) is for outer loop and inner loop runs in total a single DFS over entire graph, and we know DFS takes a time of O(N+2E). 

    // Space Complexity: O(N) + O(N),Space for recursion stack space and visited array.


    int n=adj.size();
    vector<vector<int>>adjacencyList(n);

    // To change adjacency matrix to adjacency list
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // self nodes are not considered
            if(adj[i][j]==1 && i!=j){
                adjacencyList[i].push_back(j);
                adjacencyList[j].push_back(i);
            }
        }
    }

    int visited[n] = {0};
    int count=0;
    for(int i=0;i<n;i++){
        // if the node is not visited
        if(!visited[i]) {
            // counter to count the number of provinces 
            count++;

            // dfs traversal will go and mark all its adjacent connected nodes and return.
           dfs(i, adjacencyList, visited); 
        }
    }
    return count;
}


int main(){
    // Given adjacency  matrix (nxn)
    vector<vector<int>> adj{ 
        {1,1,1,0},
        {1,1,1,0},
        {1,1,1,0},
        {0,0,0,1}
    };


    cout<<numProvinces(adj)<<endl;
}