#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Depth First Search (DFS) 

Problem Statement: Given an undirected graph, return a vector of all nodes by traversing the graph using depth-first search (DFS).

Input:
      (1)
     /  \
    /    \
   (2)━━(3)
    ┃ \ 
    ┃  \
   (4)━━(5)


Output: 1 2 4 5 3 


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

void dfs(int node, vector<vector<int>>adjacency_List, int visited[], vector<int>&ans){
    // 1. Mark node as visited 
    visited[node]=1;

    // 2. Add to it answer array
    ans.push_back(node);

    // Traverse all its neighbours
    for(auto it: adjacency_List[node]){
        // if the neighbour is not visited
        if(!visited[it]){
            dfs(it, adjacency_List, visited, ans);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<vector<int>>adjacency_List) {
    // Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.
    
    // Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.


    // Creating a visited array
    int visited[n+1] = {0}; 
    visited[1] = 1; 
    
    int start=1;

    // Creating a vector to store answer 
    vector<int>ans;

    // recursion call
    dfs(start, adjacency_List, visited, ans);

    return ans;
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    
    // Given adjacency list
    int n=5;
    vector<vector<int>>adjacency_List = {
        {},             
        {2, 3},         
        {1, 4, 5, 3},      
        {1, 2},      
        {2, 5},         
        {2, 4}   
    };

    vector <int> ans = dfsOfGraph(n, adjacency_List);
    printAns(ans);
}