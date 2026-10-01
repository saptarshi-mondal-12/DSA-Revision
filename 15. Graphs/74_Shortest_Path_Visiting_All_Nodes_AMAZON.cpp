#include<bits/stdc++.h>
using namepsace std;

/* Q. Shortest Path Visiting All Nodes - AMAZON 

You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.


Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]


Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4






---------- Intuition -----------------------------

The first thing I notice is that this is a shortest-path problem, so BFS is a natural choice because BFS explores states level by level. The twist is that simply storing the current node is not enough, because I need to know which nodes I've already visited.

For example, reaching node 0 after visiting {0,1} is different from reaching node 0 after visiting {0,1,2}. So I treat (currentNode, visitedNodes) as my BFS state.

I start BFS simultaneously from every node, because the path can start from any node. For each starting node, the visited set initially contains only that node.

At every BFS level, I try all neighbors of the current node. When I move to a neighbor, I create a new visited set and add that neighbor to it.

The variable dist represents how many edges we've traveled so far. Since BFS processes all states at distance 0, then all states at distance 1, then distance 2, and so on, the first time I find a state whose visited set contains all n nodes, I know that dist is the shortest possible distance.

For example, a valid shortest path could be:

1 → 0 → 2 → 0 → 3

Notice that we are allowed to visit a node multiple times. What matters is that eventually every node has appeared in our visited set.

So the important idea is that I'm not doing BFS just on nodes; I'm doing BFS on (node, visited-set) states.

Then explain the code

You can point to this line:

queue<pair<int, set<int>>> q;


and say:

"Each queue entry contains the current node and the set of nodes visited so far."

Then:

for (int i = 0; i < n; i++) {
    q.push({i, {i}});
}


"I initialize BFS from every node because the starting node is not fixed."

Then:

int sz = q.size();

while (sz--) {


"I'm processing one BFS level at a time. Every state in this level has the same distance."

Then:

if (visited.size() == n) {
    return dist;
}


"If I've visited all nodes, I immediately return the current distance. Because BFS explores in increasing distance order, this is guaranteed to be the shortest."

And finally:

for (int next : graph[node]) {
    set<int> newVisited = visited;
    newVisited.insert(next);

    q.push({next, newVisited});
}


"For every neighbor, I create the next state by moving to that neighbor and adding it to the visited set."

One thing I'd explicitly mention to the interviewer

There is an important distinction:

"A node can be visited multiple times; I only care whether a node has been visited at least once."

That's why a path like:

1 → 0 → 2 → 0 → 3

is perfectly valid.

The second visit to 0 doesn't add anything to the set, but it allows us to move from 0 to 3.

Complexity

For your exact implementation, I'd say:

"There can be up to n × 2^n different (node, visited-set) states. However, because I'm using std::set, copying the set costs O(n), and I can have up to O(n) neighbors in a dense graph. So the worst-case time complexity of this implementation is O(n^3 × 2^n), with O(n^2 × 2^n) space."



----------------fOLLOW UP QUES -----------------------

print path also.

Try optimal soln - bit mask

*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // Time complexity: O(n x 2^n x n x n) => (n^3 x 2^n)
        // Sapce complexity: The queue can contain up to O(n x 2^n) states, and each state stores a set of up to n elements. Thus: O(n^2 x 2^n)

        int n = graph.size();

        queue<pair<int, set<int>>> q;
        queue<vector<int>> paths;

        // Start from every node
        for (int i = 0; i < n; i++) {
            q.push({i, {i}});
            paths.push({i});
        }

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [node, visited] = q.front();
                q.pop();

                vector<int> path = paths.front();
                paths.pop();

                // Visited every node
                if (visited.size() == n) {
                    for(auto it: path){
                        cout<<it<<" ";
                    }
                    cout<<endl;
                    return dist;
                }

                for (int next : graph[node]) {
                    set<int> newVisited = visited;
                    newVisited.insert(next);

                    vector<int> newPath = path;
                    newPath.push_back(next);

                    q.push({next, newVisited});
                    paths.push(newPath);
                }
            }

            dist++;
        }

        return -1;
    }
};
