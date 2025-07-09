#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Minimum Cost to Reach Destination in Time - AMAZON 2025

There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by bi-directional roads. The roads are represented as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a road between cities xi and yi that takes timei minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.

Each time you pass through a city, you must pay a passing fee. This is represented as a 0-indexed integer array passingFees of length n where passingFees[j] is the amount of dollars you must pay when you pass through city j.

In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less. The cost of your journey is the summation of passing fees for each city that you passed through at some moment of your journey (including the source and destination cities).

Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if you cannot complete it within maxTime minutes.



Example 1:

      1     10      2
     (1)-----------(2)
 10 /                 \ 10
   /                   \
5 (0)                   (5) 3
   \                   /
  1 \                 / 15
    (3)-------------(4)
     20    10           20



Input: maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: 11
Explanation: The path to take is 0 -> 1 -> 2 -> 5, which takes 30 minutes and has $11 worth of passing fees.



Intuition-----------------------------------------------------------------------------

Using Dijkstra’s Algorithm 

You need to use Dijkstra’s algorithm, but instead of only tracking the minimum cost to reach a node, track it with respect to time

This problem is a variation of Dijkstra’s shortest path algorithm with two dimensions:
    Cost (what you want to minimize)
    Time (what you must stay within)

We use a min-heap priority queue to always process the lowest-cost paths first — but we must also track how much time it took to reach that state.

✅ Why priority Queue?
Ans: We use a priority queue in this problem to implement a variation of Dijkstra's algorithm where we are trying to find the minimum cost to reach the destination city within a time constraint.

When solving shortest-path problems (like Dijkstra), the priority queue helps us always expand the cheapest (best) current path first.

In this case:
    The "priority" is based on current total cost so far.
    The queue always gives us the path with the lowest cost to explore next.

That means:
    We first explore cheaper paths.
    If we reach a node with a more expensive path later, we can skip it (because we already found a cheaper way).



✅ Why We Return Immediately at Destination?
Ans: We know it's the cheapest valid way to reach the destination because:
    The priority queue gives us the lowest cost path first.
    All future paths to this node will be more expensive.
So we can safely return that cost.



There can be cases where the path with the minimum cost actually takes more time than maxTime, so it must be discarded, even though it’s cheaper.

This is why we must not stop at the first time we reach the destination, and we cannot rely on a simple distance[] array like in standard Dijkstra.

| Path | Time Taken | Cost |
| ---- | ---------- | ---- |
| A    | 35         | 10   |
| B    | 28         | 30   |

maxTime = 30
Path A is cheapest, but invalid (time > 30).
So you must ignore it.
Path B is valid, and must be the answer, even though it's more expensive.

We must explore all possible (cost, time) combinations for reaching each city, and only accept those where time ≤ maxTime.

We also keep a DP table:

vector<vector<int>> minCost(n, vector<int>(maxTime + 1, INT_MAX));
This means: For each city and each time (up to maxTime), we store the minimum cost to reach it in that time.
Only push to the queue if: newCost < minCost[v][newTime]

🚨 Important Rule
Even if a path has the lowest cost, it is invalid if it takes more than maxTime.
So we must track both cost and time during the path search.

*/

int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees){
    // Time Complexity: O(n × T × log(n × T))  due to the priority queue with up to n × T entries. n = number of edges, T = maxTime
    // Space complexity: O(n × T) for the minCost DP table

    int n = passingFees.size();

    // {neighbor, time}
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int time = edges[i][2];
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    // minCost[city][time] = min cost to reach 'city' in 'time' minutes
    vector<vector<int>> minCost(n, vector<int>(maxTime + 1, INT_MAX));

    // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>
        pq;

    pq.push({passingFees[0], {0, 0}}); // {cost, {node, time}}
    minCost[0][0] = passingFees[0];

    while (!pq.empty()){
        int cost = pq.top().first;
        int u = pq.top().second.first;
        int time = pq.top().second.second;
        pq.pop();

        // we are using a priority queue (min-heap ordered by cost). That guarantees:
        // The irst time we reach the destination (u == n-1) will always be with the minimum cost under the time constraint.
        // If reached destination within maxTime, return the cost
        if (u == n - 1)
            return cost;

        for (auto it : adj[u]){
            int v = it.first;
            int t = it.second;
            int newTime = time + t;
            int newCost = cost + passingFees[v];
            if (newTime <= maxTime && newCost < minCost[v][newTime]){
                minCost[v][newTime] = newCost;
                pq.push({newCost, {v, newTime}});
            }
        }
    }
    return -1;
}

int main(){
    int maxTime = 30;
    vector<vector<int>> edges = {{0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15}};
    vector<int> fees = {5,1,2,20,20,3};
    cout<<minCost(maxTime, edges, fees)<<endl;
}
