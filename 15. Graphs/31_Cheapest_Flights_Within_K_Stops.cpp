#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation: The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.



Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

*/

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k){
    // Time complexity:
    // Space complexity:

    vector<vector<pair<int, int>>> adjacencyList(n);
    for (int i = 0; i < flights.size(); i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int price = flights[i][2];
        adjacencyList[u].push_back({v, price});
    }

    vector<int> distance(n, 1e9);
    distance[src] = 0;

    queue<pair<int, pair<int, int>>> q;
    // {stops, {node, distance}}
    q.push({0, {src, 0}});

    while (!q.empty()){
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        // We stop the process as soon as the limit for the stops reaches.
        if (stops > k)
            continue;

        for (auto it : adjacencyList[node]){
            int v = it.first;
            int price = it.second;

            // We only update the queue if the new calculated dist is
            // less than the prev and the stops are also within limits.
            if (cost + price < distance[v] && stops <= k){
                distance[v] = cost + price;
                q.push({stops + 1, {v, cost + price}});
            }
        }
    }
    // If the destination node is unreachable return ‘-1’
    // else return the calculated dist from src to dst.
    if (distance[dst] == 1e9)
        return -1;
    return distance[dst];
}
int main(){
    int n = 4;
    int src=0, dst=3, k=1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};

    cout<<findCheapestPrice(n, flights, src, dst, k);
}