#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Course Schedule 1  --> Amazon

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Input: numCourses = 4,  prerequisites = {{1,0},{2,1},{3,2}}  

(3)━━━━━►(2)━━━━━►(1)━━━━━►(0)
Output: true
Explanation: It is possible to finish all the tasks in the order : 3 2 1 0.
First, we will finish task 3. Then we will finish task 2, task 1, and task 0.


Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.



Intuition: -------------------------------------------------------------------------------

Topological sort | Kahn's Algo

The questions state that the given pairs signify the dependencies of tasks. For example, the pair {u, v} signifies that to perform task v, first we need to finish task u. Now, if we closely observe, we can think of a directed edge between u and v(u -> v) where u and v are two nodes. Now, if we can think of each task as a node and every pair as a directed edge between those two nodes, the whole problem becomes a graph problem.


Example 1: numCourses = 4,  prerequisites = {{1,0},{2,1},{3,2}}
(3)━━━━━►(2)━━━━━►(1)━━━━━►(0)

For example 1, the number of tasks(considered as nodes) is 4, and pairs(considered as edges) are 3. If we draw the graph accordingly, the following illustration is produced:



Example 2: numCourses = 4,   prerequisites = {{1,2},{4,3},{2,4},{4,1}} 
(1)━━━━━►(2)━━━━━►(4)━━━━━►(3)
 ^                /
  \              /
   \            /
    -----------

Explanation: It is impossible to finish all the tasks. Let’s analyze the pairs:
For pair {1, 2} -> we need to finish task 1 first and then task 2. (order : 1 2).
For pair{4, 3} -> we need to finish task 4 first and then task 3. (order: 4 3).
For pair {2, 4} -> we need to finish task 2 first and then task 4. (order: 1 2 4 3).
But for pair {4, 1} -> we need to finish task 4 first and then task 1 but this pair contradicts the previous pair. So, it is not possible to finish all the tasks.

And For example 2, the number of tasks(considered as nodes) is 4, and pairs(considered as edges) are 4. If we draw the graph accordingly, the following illustration is produced:


Analyzing the graphs, we can conclude that performing all the tasks from the first set is possible because the first graph does not contain any cycle but as the second graph contains a cycle, performing all the tasks from the second set is impossible(there exists a cyclic dependency between the tasks). So, first, we need to identify a graph as a directed acyclic graph and if it is so we need to find out the linear ordering of the nodes as well(second part for the question: Course schedule).

Now, we have successfully reduced the problem to one of our known concepts: Detect cycle in a directed graph. We will solve this problem using the Topological Sort Algorithm or Kahn’s Algorithm.

Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are connected through directed edges and the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 

For the problem, we can also apply the algorithm used in the detection of cycles in a directed graph (using DFS) where we used to find out if the graph has a cycle or not. 

Intuition:

The intuition is to find if it is possible to perform all the tasks (i.e. The graph contains a cycle or not).
If does not contain cycle means we can complete all tasks.

*/

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    // Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

    // Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes). Extra O(N) for storing the topological sorting. Total ~ O(3N).
    int n = numCourses;

    // creating adjacency list
    vector<vector<int>> adjacencyList(n);
    for (int i = 0; i < prerequisites.size(); i++){
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];

        // To take course u, you must first take course v.  (v--->u)
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
    int count = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        // node is in your topo sort
        // so please remove it from the indegree

        for (auto it : adjacencyList[node]){
            indegree[it]--;
            if (indegree[it] == 0){
                q.push(it);
            }
        }
    }

    // if count is equal n -> means it does not contain cycle
    // means we can finish all courses
    if (count == n){
        return true;
    }
    return false;
}

int main(){
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 32}};
    cout << canFinish(numCourses, prerequisites);
}