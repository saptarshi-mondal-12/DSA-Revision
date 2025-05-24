#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Making A Large Island

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/
*/

class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v){
            return;
        }
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int largestIsland(vector<vector<int>> &grid){
    /* Time Complexity: O(N2)+O(N2) ~ O(N2) where N = total number of rows of the grid. Inside those nested loops, all the operations are taking apparently constant time. So, O(N2) for the nested loop only, is the time complexity.

    Space Complexity: O(2*N2) where N = the total number of rows of the grid. This is for the two arrays i.e. parent array and size array of size N2 inside the Disjoint set.
    */

    int n = grid.size();
    DisjointSet ds(n * n);

    // step 1: connecting cells to include them in the same group
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            if (grid[row][col] == 1){
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++){
                    int newRow = row + dr[ind];
                    int newCol = col + dc[ind];

                    // checking validity and adjacent 1's
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1){
                        // converting cell to integer
                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
    }

    // step 2: finding cell in which if we invert the value
    // we will get the largest possible group of connected 1s.

    int maxi = 0;

    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            if (grid[row][col] == 0){
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};

                // to store the uitimate parent to avoid duplicate calculation
                set<int> components;
                for (int ind = 0; ind < 4; ind++){
                    int newRow = row + dr[ind];
                    int newCol = col + dc[ind];

                    int adjNodeNo = newRow * n + newCol;
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1){
                        components.insert(ds.findUltimateParent(adjNodeNo));
                    }
                }
                int sizeTotal = 0;

                // for each parent finding its total size
                for (auto it : components){
                    sizeTotal += ds.size[it];
                }
                maxi = max(maxi, sizeTotal + 1);
            }
        }
    }

    // edge case : what if whole grid is a island i.e. 1
    for (int i = 0; i < n * n; i++){
        maxi = max(maxi, ds.size[ds.findUltimateParent(i)]);
    }
    return maxi;
}

int main(){
     vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}
    };
    int ans = largestIsland(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;
}