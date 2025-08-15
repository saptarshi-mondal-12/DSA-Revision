#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Sort the Matrix Diagonally - AMAZON 2025

A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]

[3,3,1,1]       [1,1,1,1]
[2,2,1,2]   ==> [1,2,2,2]  (All diagonals are sorted)
[1,1,1,2]       [1,2,3,3]

Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]


Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]


Practice below question in MOCK

Twist Question - https://leetcode.com/problems/sort-matrix-by-diagonals/description/

*/

void sortDiagonal(vector<vector<int>>& result, int row, int col){
    int r=result.size();
    int c=result[0].size();

    vector<int>diagonal;

    // Collect diagonal elements
    int i = row, j = col;
    while (i < r && j < c) {
        diagonal.push_back(result[i][j]);
        i++; j++;
    }

    // Sort them
    sort(diagonal.begin(), diagonal.end());

    // Put them back
    i = row; j = col;
    int idx = 0;
    while (i < r && j < c) {
        result[i][j] = diagonal[idx];
        i++; 
        j++;
        idx++;
    }
}

vector<vector<int>> diagonalSort(vector<vector<int>> &mat){
    /*
    Time complexity :
        r = number of rows
        c = number of columns
        N = r * c (total elements in the matrix)

    Number of diagonals
        From first row: c diagonals
        From first column r - 1 diagonals
        Total diagonals = c + (r - 1) = r + c - 1

    Cost for each diagonal
        Let diagonal length = L
        For a diagonal:
            Collect elements → O(L)
            Sort them → O(L log L)
            Put them back → O(L)
        So per diagonal cost ≈ O(L log L) (sorting dominates).

    Time Complexity: O(r*c) * (L log L)  ==> O(r * c * log n) where n=r*c
    Final Time complexity = O(n * log n)


    Space complexity : O(n)
        diagonal vector stores at most min(r, c) elements at a time
        Copy of matrix result = O(N)

    */

    /* For each diagonal:
        1. Collect its elements into a vector.
        2. Sort the vector.
        3. Put them back into the diagonal positions.

    Diagonals start from:
        First row: (0, 0), (0, 1), (0, 2), ...
        First column: (1, 0), (2, 0), ...
    */

    int r = mat.size();
    int c = mat[0].size();

    vector<vector<int>> result = mat;

    // Sort all diagonals starting from first row
    for (int col = 0; col < c; col++){
        sortDiagonal(result, 0, col);
    }

    // Sort all diagonals starting from first col
    for (int row = 0; row < r; row++){
        sortDiagonal(result, row, 0);
    }

    return result;
}

int main(){
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};

    vector<vector<int>> ans = diagonalSort(mat);

    for (auto it : ans){
        for (auto it1 : it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}