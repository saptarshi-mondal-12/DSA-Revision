#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Rotate Image by 90 degree
Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix
*/

vector<vector<int>> brute_rotate(vector<vector<int>> &matrix, int r, int c){
    // Time complexity - O(n^2)
    // space complexity - O(n^2)

        // some observations
        // 00 - 02
        // 01 - 12
        // 02 - 22

        // 10 - 01
        // 11 - 11
        // 12 - 21

        // 20 - 00
        // 21 - 10
        // 22 - 20

    vector<vector<int>>mat(r, vector<int>(r,0));

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[j][r-i-1]=matrix[i][j];
        }
    }
    return mat;
}


vector<vector<int>> optimal_rotate(vector<vector<int>> &matrix, int r, int c){
    // Time complexity - O(r*c) + O(r*c) = One O(r*c) is for transposing the matrix and the other is for reversing the matrix.
    // space complexity - O(1)

    // Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)
    // Step 2: Reverse each row of the matrix.

    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i=0;i<r;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    return matrix;
}


vector<vector<int>> Anti_clock_wise(vector<vector<int>> &matrix, int r, int c){
    // Time complexity - O(r*c) + O(r*c)
    // space complexity - O(1)


    // Step 1: Reverse each row of the matrix.
    // Step 2: Transpose the matrix. (transposing means changing columns to rows and rows to columns)


    for(int i=0;i<r;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    for(int i=0;i<r;i++){
        for(int j=i+1;j<c;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    return matrix;
}


int main(){
    vector<vector<int>> matrix = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7},{15,14,12,16}};
    int r = matrix.size();
    int c = matrix[0].size();
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout <<endl; 
    }  
    cout <<endl; 

    // CLOCK WISE
    // 1. brute
    // vector<vector<int>> rotated = brute_rotate(matrix, r, c);

    // 2. optimal
    // vector<vector<int>> rotated = optimal_rotate(matrix, r, c);


    // ANTI CLOCK WISE
    vector<vector<int>> rotated = Anti_clock_wise(matrix, r, c);



    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
        for (int j = 0; j < rotated[0].size(); j++) {
            cout << rotated[i][j] << " ";
        }
        cout <<endl; 
    }  
}