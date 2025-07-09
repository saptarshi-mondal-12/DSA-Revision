#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Print All Paths From Source to Target

Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).



Example 1:

  (0)--------->(1)
   |            |
   |            |
   |            |
   v            v
  (2)--------->(3)


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

*/

void dfs(int currNode, int target, vector<int> &path, vector<vector<int>> &ans, vector<vector<int>> &adjacencyList){

    // add currNode to our answer
    path.push_back(currNode);

    // if currNode is the target, we get a path i.e from siurce to target
    if (currNode == target){
        ans.push_back(path);
    }
    else{
        // Explore all possible path
        for (auto it : adjacencyList[currNode])
        {
            dfs(it, target, path, ans, adjacencyList);
        }
    }

    // Backtrack: remove current node before returning to previous state
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph){
    /* Time compexity: O(N + E) + O(P × L) 
    There could be exponentially many paths in the worst case. For each path, we spend O(L) time to build/store it in ans. where N = number of nodes (vertices) E = number of edges, P = number of valid paths from source to target, L = average length of a path (at most V in the worst case)

    Space complexity: O(N + E) + O(P × L) + O(N) for recursion stack space */

    // no of nodes
    int n = graph.size();

    // Creating Adjacency list
    vector<vector<int>> adjacencyList(n);
    for (int i = 0; i < n; i++){
        for (auto it : graph[i]){
            adjacencyList[i].push_back(it);
        }
    }

    // fianl answer
    vector<vector<int>> ans;

    // vector to store our possible path from source to target
    vector<int> path;
    int target = n - 1;

    dfs(0, target, path, ans, adjacencyList);

    return ans;
}

int main(){

    vector<vector<int>> graph = {{1,2}, {3}, {3}, {}};
    vector<vector<int>>ans = allPathsSourceTarget(graph);
    for(int i=0;i<ans.size();i++){
        for(auto it : ans[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}