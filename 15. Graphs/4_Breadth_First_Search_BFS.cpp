#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Breadth First Search (BFS) ---> Level Order Traversal

Problem Statement: Given an undirected graph, return a vector of all nodes by traversing the graph using breadth-first search (BFS).

Input:
     (1)
     /  \
    /    \
   (2)━━(5)
    ┃  / ┃
    ┃ /  ┃
   (3)━━(4)

Output: 1 2 5 3 4 (level wise)


Input:

                1
            /       \
           2         7
         /   \     /   \ 
        3     6   8     10
       / \       /
      4   5     9

Output: 1 2 7 3 6 8 10 4 5 9
*/

// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int n, vector<vector<int>>adjacency_List) {
    // Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.
    // Space Complexity: O(2N) ~ O(N), Space for queue data structure visited array.


    // 1. Creating a visited array
    int visited[n+1] = {0}; 
    visited[1] = 1; 

    // 2. push the initial starting node 
    queue<int> q;
    q.push(1); 

    // 3. to store answer
    vector<int> bfs; 

    // 4. Iterate till the queue is empty 
    while(!q.empty()) {
       // get the topmost element in the queue 
        int node = q.front(); 
        q.pop(); 
        bfs.push_back(node); 

        // traverse for all its neighbours 
        for(auto it : adjacency_List[node]) {
            // if the neighbour has previously not been visited, store in Q and mark as visited 
            if(!visited[it]) {
                visited[it] = 1; 
                q.push(it); 
            }
        }
    }
    return bfs; 
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    // Input 1: 
    // Given adjacency list
    // int n=5;
    // vector<vector<int>>adjacency_List = {
    //     {},             // 0 (dummy, since indexing starts at 1)
    //     {2, 5},         // 1
    //     {1, 3, 5},      // 2
    //     {2, 4, 5},      // 3
    //     {3, 5},         // 4
    //     {1, 2, 3, 4}    // 5
    // };

    // -------------------------------------------------------


    
    // Input 2: Given adjacency list
    int n=10;
    vector<vector<int>> adjacency_List = {
        {},             // 0 (dummy)
        {2, 7},         // 1
        {1, 3, 6},      // 2
        {2, 4, 5},      // 3
        {3},            // 4
        {3},            // 5
        {2},            // 6
        {1, 8, 10},     // 7
        {7, 9},         // 8
        {8},            // 9
        {7}             // 10
    };
    

    vector <int> ans = bfsOfGraph(n, adjacency_List);
    printAns(ans);
}