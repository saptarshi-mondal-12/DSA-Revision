#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Set Matrix Zero 
Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
Output:[[1,0,1],
        [0,0,0],
        [1,0,1]]
Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.
 
Input: matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output:[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Explanation:Since matrix[0][0]=0 and matrix[0][3]=0. Therefore 1st row, 1st column and 4th column will be set to 0

Note: Here, we are assuming that the matrix does not contain any negative numbers. 
But if it contains negatives, we need to find some other ways to mark the cells instead of marking them with -1.
*/



vector<vector<int>> brute_zeroMatrix(vector<vector<int>> &matrix, int r, int c){
    // Time complexity - O(r*c) * (r+c) 
    // space complexity - O(r*c)


    // using dummy matrix
    vector<vector<int>>ans=matrix;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if (ans[i][j]==0){
                // set all 0 in ith row
                for(int k=0;k<c;k++){
                    matrix[i][k]=0;
                }

                // set all 0 in jth column
                for(int k=0;k<r;k++){
                    matrix[k][j]=0;
                }
            }
        }
    }
    return matrix;
}

vector<vector<int>> better_zeroMatrix(vector<vector<int>> &matrix, int r, int c){
    // Time complexity - O(r*c) + O(r*c) = O(2*(r*c))
    // space complexity - O(r) + O(c)

    /* 1. If any cell (i,j) contains the value 0, we will mark ith index of row array 
    i.e. row[i] and jth index of col array col[j] as 1. It signifies that all the elements 
    in the ith row and jth column will be 0 in the final matrix.
    
    2. Finally, we will again traverse the entire matrix and we will put 0 into all the cells (i, j) 
    for which either row[i] or col[j] is marked as 1.*/

    // row array
    vector<int>row(r,0);

    // col array
    vector<int>col(c,0);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==0){
                // mark ith index of row wih 1:
                row[i]=1;

                // mark jth index of col wih 1:
                col[j]=1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }

        }
    }

    return matrix;
}

vector<vector<int>> optimal_zeroMatrix(vector<vector<int>> &matrix, int r, int c){
    // Time complexity - O(r*c) + O(r*c) = O(2*(r*c))
    // space complexity - O(1)

    int col0=1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==0){
                // mark i-th row
                matrix[i][0]=0;

                // mark j-th column:
                if(j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col0=0;
                }

            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(matrix[i][j]!=0){
                // check for col & row
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st row & then 1st col
    // change row
    if(matrix[0][0]==0){
        for(int j=0;j<c;j++){
            matrix[0][j]=0;
        }
    }

    // change column
    if(col0==0){
        for (int i = 0; i < r; i++) {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}


int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int r = matrix.size();
    int c = matrix[0].size();

    // 1. brute
    vector<vector<int>> ans = brute_zeroMatrix(matrix, r, c);

    // 2. better
    // vector<vector<int>> ans = better_zeroMatrix(matrix, r, c);

    // 3. optimal
    // vector<vector<int>> ans = optimal_zeroMatrix(matrix, r, c);


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(ans[i][j]==-1) cout<<0<<" ";
            else cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}