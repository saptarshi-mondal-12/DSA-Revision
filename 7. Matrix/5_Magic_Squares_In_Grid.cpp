#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Magic Squares In Grid
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
*/


/* Intuition - Manual Scan
The given grid may contain integers above 9, but a magic grid may only contain integers 1 to 9.
The given grid may contain duplicate values, but every value in a magic grid must be distinct. In other words, no duplicate values are allowed.

With the given grid, you want to find the number of subarrays in grid that are magic squares. A 3 x 3 magic square is defined as a 3 x 3 array containing distinct integers from 1 to 9 whose rows, columns, and diagonals all have the same sum.
*/

int numMagicSquaresInside(vector<vector<int>>& grid) {
    // Time complexity = O(row*col)
    // space complexity = O(1)

    int row = grid.size();
    int col = grid[0].size();
    int result = 0;

    for (int i = 0; i <= row - 3; i++) {
        for (int j = 0; j <= col - 3; j++) {
            // Checking duplicate
            set<int> seen;
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    int num = grid[i + r][j + c];
                    if (num >= 1 && num <= 9) {
                        seen.insert(num);
                    }
                }
            }

            if (seen.size() == 9) {
                // 1. Check if diagonal sums are the same
                int diagonal1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int diagonal2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];

                // 2. Check if all row sums are the same as diagonal
                int row1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                int row2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                int row3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];

                // 3. Check if all column sums are the same as diagonal
                int col1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                int col2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                int col3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];

                if (diagonal1 == diagonal2 && 
                    row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1 &&
                    col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal1) {
                    result++;
                }
            }
        }
    }
    return result;
}


int main(){
    vector<vector<int>> matrix = {{4,3,8,4}, {9,5,1,9}, {2,7,6,2}};
	cout<<numMagicSquaresInside(matrix);
}