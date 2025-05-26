#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Clone Graph

Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.

---------------------------------------------------------------------------------------------------
Clone Graph - Interview Explanation Script
"Sure! This problem is about making a deep copy of an undirected graph, starting from a given node.
Each node has a value and a list of neighbors, and we need to create a completely new graph that looks identical in structure but uses new memory.

🔍 Intuition:
The main challenge is that the graph might contain cycles or shared neighbors, so we can't just use simple recursion without tracking what we've already cloned — otherwise we risk going into infinite loops or duplicating nodes.

🚀 Approach:
I use a Depth-First Search (DFS) approach along with a hash map to keep track of already-cloned nodes.

Here’s what I do:

I maintain a map called visited that maps original nodes to their cloned copies.

I start DFS from the given node.

For every node:

If it’s already in the map, I return the cloned version.

Otherwise, I create a new node.

Then, I recursively clone all its neighbors and add them to the new node’s neighbors list.

This ensures each node is cloned only once, and all references are maintained correctly.

🧪 Example (optional):
Suppose Node 1 is connected to Nodes 2 and 4, and there's a cycle through Node 3. My DFS starts at Node 1, clones it, then visits Node 2, clones it, and so on. If a node is already visited, I reuse the existing clone from the map.

⚙️ Data Structures:
Hash Map (unordered_map<Node*, Node*>) to store already cloned nodes

Recursive DFS (or BFS using a queue)

📊 Time & Space Complexity:
Time: O(N) — every node and edge is visited once.

Space: O(N) — for the visited map and recursion stack.

✅ Why this works:
The visited map is crucial to avoid infinite recursion and ensures that shared neighbors point to the same cloned object, not separate duplicates.

🔚 Conclusion:
So overall, my solution handles cycles, avoids duplicating work, and ensures the cloned graph structure is exactly the same as the original."
*/






// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    // A map to store the cloned nodes
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If the node was already cloned, return its clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Clone the node (with empty neighbors for now)
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // Clone all the neighbors
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};
