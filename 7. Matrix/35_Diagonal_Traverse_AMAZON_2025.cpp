#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Diagonal Traverse - AMAZON 2025 

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

[1, 2, 3]
[4, 5, 6]
[7, 8, 9]

    -->   ---
   /  /  / 
     /  /
    /  /
    -->

    1
    2,4
    7,5,3
    6,8
    9

Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]

*/

vector<int> findDiagonalOrder(vector<vector<int>> &mat){
    // Time Complexity = O(m x n)
    // Space complexity: O(m x n)

    int m = mat.size();
    int n = mat[0].size();

    vector<int> result;
    int count = 0;

    // Traverse starting from each column of the first row
    for (int col = 0; col < n; col++){
        vector<int> temp;
        int i = 0, j = col;

        while (i < m && j >= 0){
            temp.push_back(mat[i][j]);
            i++;
            j--;
        }

        if (count % 2 == 0){
            reverse(temp.begin(), temp.end());
        }
        result.insert(result.end(), temp.begin(), temp.end());
        count++;
    }


    // Traverse starting from each row of the last column (excluding row=0)
    for (int row = 1; row < m; row++){
        vector<int> temp;
        int i = row, j = n - 1;

        while (i < m && j >= 0){
            temp.push_back(mat[i][j]);
            i++;
            j--;
        }

        if (count % 2 == 0){
            reverse(temp.begin(), temp.end());
        }
        result.insert(result.end(), temp.begin(), temp.end());
        count++;
    }

    return result;
}

int main(){
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> ans = findDiagonalOrder(mat);

    for (auto it : ans){
        cout << it << " ";
    }
}