#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Travelling Salesman Problem

Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Input: cost = [[0, 111], [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.


Input: cost = [[0, 1000, 5000], [5000, 0, 1000], [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000+1000+1000 = 3000
*/

// Recursion ---------------------------------------------------------------------
int tspRec(int curr, vector<int> &visited, vector<vector<int>> &cost, int n){
    // Step 1: Base Case — Already Visited
    if (visited[curr])
        return INT_MAX; // already visited, invalid


    // Step 2: Mark Current City as Visited
    visited[curr] = 1;


    // Step 3: Check if All Cities Visited
    bool allVisited = true;
    for (int i = 0; i < n; i++)
        if (!visited[i]){
            allVisited = false;
        }
    

    // Step 4: Return to City 0 (End Condition)
    if (allVisited){
        visited[curr] = 0;    // backtrack
        return cost[curr][0]; // return to starting city (0)
    }

    // Step 5: Recursive Exploration
    int ans = INT_MAX;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            int temp = tspRec(i, visited, cost, n);
            if (temp != INT_MAX){
                ans = min(ans, cost[curr][i] + temp);
            }
        }
    }

    // Step 6: Backtrack
    visited[curr] = 0; // backtrack
    return ans;
}
int tsp(vector<vector<int>> &cost){
    // Time: O(n!) because for each city, we try n-1 unvisited cities. This becomes extremely slow even for n = 10 (10! = 3.6 million paths).
    // Space: O(n) due to recursion stack and visited array.

    int n = cost.size();
    vector<int> visited(n, 0);
    return tspRec(0, visited, cost, n);
}


// Memoization -------------------------------------------------------------------

/* 🗣️ Sample Answer:
I know that the recursive solution has exponential time complexity — roughly O(n!), because it explores all possible permutations.

I’m aware that to optimize it, we can use dynamic programming with memoization, often involving a visited state — typically represented using bitmasking for efficiency. But to be honest, I haven't fully mastered bitmasking yet.

That said, for up to 10 cities, I can write a DP with memoization using a set or string to represent the visited state instead of bitmask — it won’t be the most optimal, but it will work within reasonable constraints.

If you're okay with that, I’d be happy to implement it.

*/


int main() {
    vector<vector<int>> cost2 = {
        {0, 1000, 5000},
        {5000, 0, 1000},
        {1000, 5000, 0}
    };
    cout << "Minimum cost: " << tsp(cost2) << endl;

    return 0;
}