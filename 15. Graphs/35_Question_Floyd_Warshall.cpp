#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Find the City With the Smallest Number of Neighbors at a Threshold Distance

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.


Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.

*/

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold){
    // Time Complexity: O(V^3), as we have three nested loops each running for V times
    // Space Complexity: O(V^2) , where V = no. of vertices

    
    vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < edges.size(); i++){
        int r = edges[i][0];
        int c = edges[i][1];
        int wt = edges[i][2];
        matrix[r][c] = wt;
        matrix[c][r] = wt;
    }

    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;

    // via means source via/through destination
    for (int via = 0; via < n; via++){
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++){
            // Pick all vertices as destination for the above picked source
            for (int j = 0; j < n; j++){
                // shortest path from i to j
                if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }

    int cntCity = n;
    int cityNo = -1;
    for (int city = 0; city < n; city++){
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++){
            if (matrix[city][adjCity] <= distanceThreshold){
                cnt++;
            }
        }
        if (cnt <= cntCity){
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;
}

int main(){
    int n = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

    cout << findTheCity(n, edges, distanceThreshold);
}