#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Count Submatrices With All Ones - AMAZON 2025

Given an m x n binary matrix mat, return the number of submatrices that have all ones.

Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2.
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.


Input: mat = [[0,1,1,0],
              [0,1,1,1],
              [1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3.
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2.
There are 2 rectangles of side 3x1.
There is 1 rectangle of side 3x2.
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.

*/

int numSubmat(vector<vector<int>> &mat){
    // Time complexity: O(m^2 * n)
    // Space complexity: O(m*n)

    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> dummy(m, vector<int>(n, 0));
    int result = 0;

    // Step 1: compute width matrix
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j == 0){
                dummy[i][j] = mat[i][j];
            }
            else{
                if (mat[i][j] == 0){
                    dummy[i][j] = 0;
                }
                else{
                    dummy[i][j] = dummy[i][j - 1] + 1;
                }
            }

            // Step 2: count submatrices using width
            int curr = dummy[i][j];

            for (int k = i; k >= 0 && curr > 0; k--){
                curr = min(curr, dummy[k][j]);
                result += curr;
            }
        }
    }
    return result;
}

int main(){
    vector<vector<int>> mat = {{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}};
    int result = numSubmat(mat);
    cout << "The number of squares: " << result << endl;
}