#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V; // number of vertices
    vector<vector<int>> adjList; // adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to u’s list
        adjList[v].push_back(u); // Add u to v’s list (because undirected)
    }

    // print the graph
    void printGraph() {
        // Time complexity: O(V+2E)
        
        for (int i = 0; i < V; ++i) {
            cout << "Node " << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // print graph ---> level wise ----> using breadth first search - 
    void printGraph_BFS(){
        // Time Complexity: O(V) + O(2E), Where V = Nodes, 2E is for total edges as we traverse all adjacent nodes.
        // Space Complexity: O(2V) ~ O(V), Space for queue data structure visited array.

        // 1. Creating a visited array
        int visited[V+1] = {0}; 
        visited[0] = 1; 

        // 2. push the initial starting node 
        queue<int> q;
        q.push(0); 


        // 4. Iterate till the queue is empty 
        while(!q.empty()) {
        // get the topmost element in the queue 
            int node = q.front(); 
            q.pop(); 
            cout<<node<<" "; 

            // traverse for all its neighbours 
            for(auto it : adjList[node]) {
                // if the neighbour has previously not been visited, store in Q and mark as visited 
                if(!visited[it]) {
                    visited[it] = 1; 
                    q.push(it); 
                }
            }
        } 
        cout<<endl;
    }

};

int main(){
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();
    g.printGraph_BFS();
}