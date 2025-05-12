#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Course Schedule 2  --> Amazon

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]



Intuition: -------------------

Same code - topological sort | Kahn's Algorithm

The intuition is to find the linear ordering in which the tasks will be performed if it is possible to perform all the tasks otherwise, to return an empty array.

*/

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites){
    // Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

    // Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes). Extra O(N) for storing the topological sorting. Total ~ O(3N).

    int n = numCourses;

    // creating adjacency list
    vector<vector<int>> adjacencyList(n);
    for (int i = 0; i < prerequisites.size(); i++){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjacencyList[v].push_back(u);
    }

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++){
        for (auto it : adjacencyList[i]){
            indegree[it]++;
        }
    }

    // Pushing all 0 indegree to queue
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> result;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);
        // node is in your topo sort
        // so please remove it from the indegree

        for (auto it : adjacencyList[node]){
            indegree[it]--;
            if (indegree[it] == 0){
                q.push(it);
            }
        }
    }
    if (result.size() == numCourses)
        return result;
    return {};
}

int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3,2}};
    vector<int> ans = findOrder(numCourses, prerequisites);

    for (auto node : ans){
        cout << node << " ";
    } 
}