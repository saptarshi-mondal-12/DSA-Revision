#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Find the Minimum Area to Cover All Ones 1

You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/?envType=daily-question&envId=2025-08-22


Input: grid = [[0,1,0],[1,0,1]]
Output: 6
Explanation: The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.


Input: grid = [[1,0],[0,0]]
Output: 1
Explanation: The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

*/

int minimumArea(vector<vector<int>> &grid){
    // Time complexity: O(n * m)
    // Space complexity: O(1)

    /* Intuition:
    During traversal, we need to find the upper, lower, left, and right boundaries
    where 1  appears. Once the boundaries are identified, we calculate the minimum
    area they enclose.*/

    int n = grid.size();
    int m = grid[0].size();

    int min_i = n, max_i = 0;
    int min_j = m, max_j = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                min_i = min(min_i, i);
                max_i = max(max_i, i);
                min_j = min(min_j, j);
                max_j = max(max_j, j);
            }
        }
    }
    return (max_i - min_i + 1) * (max_j - min_j + 1);
}

int main(){
    
}