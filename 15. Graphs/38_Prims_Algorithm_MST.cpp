#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Prim's Algorithm 

Problem Statement: -------> (Finding MST)

Given a weighted, undirected, and connected graph of V vertices and E edges.The task is to find the minimum spanning tree where you need to return weight for each edge in the MST.

Input Format: V = 5, edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}}
Result: {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 4, 5}}
Explanation: sum is 16


Input Format: V = 5, edges = { {0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}}
Result: {{0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}}
Explanation: sum is 5

*/

vector<pair<pair<int, int>, int>> spanningTree(int v, vector<vector<int>> edges){
    /* Time compleixty: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
    
    The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE). 

    Space complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most. */


    vector<vector<pair<int,int>>> adjacencyList(v);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adjacencyList[u].push_back({wt, v});
        adjacencyList[v].push_back({wt, u});
    }
    
    // visited array
    vector<int> vis(v, 0);

    // To store MST
    vector<pair<pair<int, int>, int>>mst;


    // {wt, node, parent}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0,{0, -1}});

    int sum = 0;

    while (!pq.empty()){
        int wt=pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (vis[node] == 1)
            continue;

        // mark visited
        vis[node] = 1;
        if (parent != -1) {
            mst.push_back({{parent, node}, wt});
        }
        sum += wt;
        for (auto it : adjacencyList[node]){
            int edW = it.first;
            int adjNode = it.second;
            if (!vis[adjNode]){
                pq.push({edW, {adjNode,node}});
            }
        }
    }
    return mst;
}

int main(){
    int v = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};
    vector<pair<pair<int, int>, int>> mst = spanningTree(v, edges);
    for(auto it: mst){
        int u=it.first.first;
        int v=it.first.second;
        int weight=it.second;
        cout<<u<<" "<<v<<" "<<weight<<endl;
    }
}