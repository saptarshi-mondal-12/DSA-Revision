#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Peak element II

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

*/

void brute_findPeakGrid(vector<vector<int>>matrix, int n, int m){
    // time complexity - O(n*m)
    // space complexity - O(2)

    /* check for left, right, top, bottom 

      ^
    <ele>
      v
    
    */
    vector<int>result={-1,-1};

    for(int i=0;i<n;i++){
        int flag = false;
        for(int j=0;j<m;j++){

            int left=-1;
            int right=-1;
            int top=-1;
            int bottom=-1;

            if(i>0){
                top=matrix[i-1][j];
            }
            if(i!=n-1){
                bottom=matrix[i+1][j];
            }
            if(j>0){
                left=matrix[i][j-1];
            }
            if(j!=m-1){
                right=matrix[i][j+1];
            }

            // cout<<matrix[i][j]<<" "<<left<<" "<<right<<" "<<top<<" "<<bottom<<endl;

            if(matrix[i][j] > left && matrix[i][j] > right && matrix[i][j] > top && matrix[i][j] > bottom){
                result[0]=i;
                result[1]=j;
                flag = true;
                break;
            }   
        }
        if(flag){
            break;
        }
    }
    cout<<result[0]<<" "<<result[1]<<" ans = "<<matrix[result[0]][result[1]]<<endl;
}

int findMaxIndex(vector<vector<int>>matrix, int n, int m, int col){
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        // cout<<matrix[i][col]<<endl;
        if (matrix[i][col] > maxValue){
            maxValue=matrix[i][col];
            index=i;
        }
    }
    cout<<"maxValue = "<<maxValue<<" index = "<<index<<endl;
    return index;
}

void optimal_findPeakGrid(vector<vector<int>>matrix, int n, int m){
    // time complexity - O(log m * n)
    // space complexity - O(1)

    /* [10, 1, 15]
       [25, 23, 17]
       [27,  7,  8]

       Intuition - 1. Select col and find max element from that column and find the row(where max eleement is present).
       2. check its surroundings and if it meets all conditions return (row,col) answer else shift col to col-1 to left if left element is greater else col+1 to serch right half. repeat same process 

    */

    vector<int>result={-1,-1};
    int low=0, high=m-1;

    while(low<=high){
        int mid=(low+high)/2;
        int maxRowIndex=findMaxIndex(matrix,n,m,mid);

        int left=mid-1 >= 0 ? matrix[maxRowIndex][mid-1]:-1;
        int right=mid+1 < m ? matrix[maxRowIndex][mid+1]:-1;

        cout<<"mid = "<<mid<<" maxRowIndex = "<<maxRowIndex<<"matrix[maxRowIndex][mid] = "<<matrix[maxRowIndex][mid]<<endl;

        if(matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid]> right){
            result[0]=maxRowIndex;
            result[1]=mid;
            break;
        }
        else if(matrix[maxRowIndex][mid] < left){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<result[0]<<" "<<result[1]<<" ans = "<<matrix[result[0]][result[1]]<<endl;
}


int main(){
    int row = 5, col = 3;
    vector<vector<int>> matrix = {{10, 19, 15},{2, 43, 17},
                                  {7, 2, 8}, {1,35,1},{1,1,1}};

    // 1. brute
    // brute_findPeakGrid(matrix,row,col);

    // 2. optimal
    optimal_findPeakGrid(matrix,row,col);
}
