#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1



Intuition: ----------------------------------------------------------------------------

Reference Q. 33

*/

int networkDelayTime(vector<vector<int>> &times, int n, int k){
    vector<int> distance(n + 1, 1e8);
    distance[k] = 0;

    for (int notimes = 0; notimes < n - 1; notimes++){
        for (int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            if (distance[u] != 1e8 && distance[u] + wt < distance[v])
            {
                distance[v] = distance[u] + wt;
            }
        }
    }

    int mx = INT_MIN;
    for (int i = 1; i <= n; i++){
        if (distance[i] == 1e8)
            return -1;
        mx = max(mx, distance[i]);
    }

    return mx;
}

int main(){
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;

    int result = networkDelayTime(times, n, k);
    cout << "Output: " << result << endl;  // Expected Output: 2
}