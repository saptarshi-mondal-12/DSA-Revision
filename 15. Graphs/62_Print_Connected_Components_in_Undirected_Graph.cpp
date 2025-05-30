#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Connected Components in an Undirected Graph

Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
Explanation:

Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
Output: [[0, 1, 6], [2, 3, 4], [5]]
*/

void dfs(int node, vector<vector<int>> &adjacencyList, vector<int> &visited, vector<int> &component){
    visited[node] = 1;
    component.push_back(node);

    for (auto neighbour : adjacencyList[node]){
        if (!visited[neighbour]){
            dfs(neighbour, adjacencyList, visited, component);
        }
    }
}

vector<vector<int>> getComponents(int n, vector<vector<int>> &edges){
    vector<vector<int>> adjacencyList(n);

    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    vector<int> visited(n, 0);
    vector<vector<int>> provinces;

    for (int i = 0; i < n; i++){
        if (!visited[i]){
            vector<int> component;
            dfs(i, adjacencyList, visited, component);
            provinces.push_back(component);
        }
    }

    return provinces;
}

int main(){
    int n=7;
    vector<vector<int>> edges={{0, 1}, {6, 0}, {2, 4}, {2, 3}, {3, 4}};

    vector<vector<int>>ans=getComponents(n,edges);
    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}