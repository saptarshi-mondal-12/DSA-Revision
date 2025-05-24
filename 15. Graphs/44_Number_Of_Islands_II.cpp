#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Number Of Islands II

You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.


Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011



Input: n = 4
m = 5
k = 4
A = {{0,0},{1,1},{2,2},{3,3}}

Output: 1 2 3 4
Explanation:
0.  00000
    00000
    00000
    00000
1.  10000
    00000
    00000
    00000
2.  10000
    01000
    00000
    00000
3.  10000
    01000
    00100
    00000
4.  10000
    01000
    00100
    00010

https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/

Intuition: 

Grid mapping - 0 1 2 3 4
               5 6 7 8 9
               10 11 12 13 14
               15 16 17 18 19

But how we know (2,1) is 11

int nodeNo = row * m + col;
int adjNodeNo = adjr * m + adjc;
*/


class DisjointSet{
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if (ulp_u == ulp_v){
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
    /* Time Complexity: O(Q*4α) ~ O(Q) where Q = no. of queries. The term 4α is so small that it can be considered constant.

    Space Complexity: O(Q) + O(N*M) + O(N*M), where Q = no. of queries, N = total no. of rows, M = total no. of columns. The last two terms are for the parent and the size array used inside the Disjoint set data structure. The first term is to store the answer. */


    DisjointSet ds(n * m);
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int count = 0;
    vector<int> ans;
    for (auto it : operators){
        int row = it[0];
        int col = it[1];
        
        if (visited[row][col] == 1){
            ans.push_back(count);
            continue;
        }
        else{
            visited[row][col] = 1;
            count++;

            // row-1, col
            // row, col+1
            // row+1, col
            // row, col-1
            int dr[4] = {-1, 0, 1, 0};
            int dc[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];

                if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m && visited[adjr][adjc] == 1){
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;

                    if (ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNodeNo)){
                        count--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
            ans.push_back(count);
        }
    }
    return ans;
}

int main(){
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    vector<int> ans = numOfIslands(n, m, operators);
    for (auto res : ans) {
        cout << res << " ";
    }
    cout << endl;
}