#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Path of greater than equal to k length

Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path length greater than or equal to k,(without any cycle) starting from a given source and ending at any other vertex.
Source vertex should always be  0.

Input:V = 4 , E = 3 and K = 8
A[] = [0, 1, 5, 1, 2, 1, 2, 3, 1]
Output: 0
Explanation: There exists no path which has a distance  of 8.


Input: V = 9, E = 14 and K = 60
A[] = [0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 11, 2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9, 3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6, 8, 6, 7, 8, 7]
Output: 0



Follow up Ques: Print the path
*/

bool dfs(int node, int k, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, int currWeight, vector<int> &path){
    if (currWeight >= k)
        return true;

    visited[node] = true;

    for (auto it : adj[node]){
        int nextNode = it.first;
        int weight = it.second;

        if (!visited[nextNode]){
            path.push_back(nextNode);
            if (dfs(nextNode, k, adj, visited, currWeight + weight, path)){
                return true;
            }

            path.pop_back(); // backtrack
        }
    }

    visited[node] = false; // backtrack
    return false;
}

bool pathMoreThanK(int V, int E, int k, int *a){
    // Create the adjacency list
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < 3 * E; i += 3){
        int u = a[i];
        int v = a[i + 1];
        int w = a[i + 2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(V, false);

    // follow up - printing path
    vector<int> path = {0};

    // (start node, target weight, adjacency list, visited nodes, initial path weight)
    bool ans = dfs(0, k, adj, visited, 0, path);


    // Print the path - follow up ques
    cout<<"Path: ";
    for(auto it: path){
        cout<<it<<" ";
    }
    cout<<endl;
    return ans;
}

int main() {
    int V = 9, E = 14, K = 60;
    int A[] = {0, 1, 4, 0, 7, 8, 1, 2, 8, 1, 7, 11, 2, 3, 7, 2, 5, 4, 2, 8, 2, 3, 4, 9, 3, 5, 14, 4, 5, 10, 5, 6, 2, 6, 7, 1, 6, 8, 6, 7, 8, 7};

    cout<<pathMoreThanK(V, E, K, A)<<endl;
}
