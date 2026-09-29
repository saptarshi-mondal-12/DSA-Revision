
/* Q. Minimum Fuel Cost to Report to the Capital - AMAZON 

There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

Return the minimum number of liters of fuel to reach the capital city.

 
Input: roads = [[0,1],[0,2],[0,3]], seats = 5
Output: 3
Explanation: 
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
It costs 3 liters of fuel at minimum. 
It can be proven that 3 is the minimum number of liters of fuel needed.


Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
Output: 7
Explanation: 
- Representative2 goes directly to city 3 with 1 liter of fuel.
- Representative2 and representative3 go together to city 1 with 1 liter of fuel.
- Representative2 and representative3 go together to the capital with 1 liter of fuel.
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative5 goes directly to the capital with 1 liter of fuel.
- Representative6 goes directly to city 4 with 1 liter of fuel.
- Representative4 and representative6 go together to the capital with 1 liter of fuel.
It costs 7 liters of fuel at minimum. 
It can be proven that 7 is the minimum number of liters of fuel needed.
Example 3:


---------------Intuition --------------------------------
For every road, count how many people need to cross that road, then calculate how many cars are required to carry them.
Since the graph is a tree and the capital is city 0, everybody eventually moves toward city 0.

Since the graph is a tree and city 0 is the capital, I can root the tree at 0. Every representative has to move from their city toward the root.
For any edge connecting a child to its parent, I need to know how many representatives are coming from that child's subtree. If there are p representatives and each car has seats seats, then the number of cars needed across that edge is ceil(p / seats). Since crossing one edge costs one liter per car, the fuel contributed by that edge is also ceil(p / seats).
So I can use a postorder DFS. First, I recursively process all children. Each child returns the number of representatives in its subtree. I add those counts together and add one for the representative of the current city.
Before returning that count to the parent, I calculate how many cars are needed to move those representatives across the current edge.

I don't calculate fuel for the root because the root is the destination and has no parent edge."

To calculate ceiling division using integers, I use (p + seats - 1) / seats.



*/

class Solution {
public:
    long long dfs(int node, int parent, vector<vector<int>>& adj,
                  long long &result, int seats) {
        
        long long passengers = 1;

        for (auto it : adj[node]) {
            if (it != parent) {
                long long p = dfs(it, node, adj, result, seats);

                passengers += p;

                // Cars needed from this subtree
                result += (p + seats - 1) / seats;
            }
        }

        return passengers;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;

        vector<vector<int>> adj(n);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long result = 0;

        dfs(0, -1, adj, result, seats);

        return result;
    }
};
